#ifndef LLVM_LIB_ANALYSIS_DAGSLICER_H
#define LLVM_LIB_ANALYSIS_DAGSLICER_H

#include "llvm/ADT/STLFunctionalExtras.h"
#include "llvm/ADT/StringRef.h"

namespace llvm {

class Value;
class raw_ostream;

namespace DAGSlicer {

void enumeratePatterns(const Value *Root, unsigned MinDepth, unsigned MaxDepth,
                       function_ref<void(StringRef Pattern)> Callback);

void recordPatterns(const Value *Root, unsigned AnalysisDepth,
                    unsigned MinDepth, unsigned MaxDepth);

// Serialize the integer-expression DAG rooted at \p Root into a single-line,
// sharing-preserving SSA record, truncated at \p MaxDepth. Unlike
// enumeratePatterns (which expands every sub-DAG into an unfolded tree), this
// emits the single maximal truncation once, so a reused value appears as a
// single node referenced by id.
//
// The format is a "; "-joined list of `%I = Op(ref, ...)` statements written
// root-first (%0 is the root), so every operand reference is either a boundary
// input `argJ` or a node `%K` with K > I. Operation nodes are numbered in
// reverse-postorder; boundary values become `argJ` by first appearance, with a
// shared value reusing its arg. This matches the PatternDag.from_ssa grammar in
// synth_xfer's pattern_dsl.py. Op names, types and widths are not emitted;
// commutativity is recoverable from the op name. Emits nothing if \p Root is not
// an expandable node or the truncation has fewer than two operation nodes.
void serializeTruncatedDAG(const Value *Root, unsigned MaxDepth,
                           raw_ostream &OS);

// Depth-budgeted entry point for the computeKnownBits hook: mirrors
// recordPatterns' budget logic but logs one truncated DAG instead of every
// sub-pattern. The local depth budget is MaxDepth - AnalysisDepth.
void recordDAG(const Value *Root, unsigned AnalysisDepth, unsigned MinDepth,
               unsigned MaxDepth);

} // namespace DAGSlicer
} // namespace llvm

#endif // LLVM_LIB_ANALYSIS_DAGSLICER_H
