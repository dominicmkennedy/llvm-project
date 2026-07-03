namespace Shl_Lshr_arg0_arg1_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFF00ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFF000ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x2ULL}, 0xFFFFFF03ULL, 0x0ULL},
  {32u, {0x0ULL, 0x0ULL}, {0xFFFFFFFFULL, 0x0ULL}, 0x0ULL, 0x80000000ULL},
  {64u, {0xFFE0000000000000ULL, 0xFFFFFFFFFFFFFF80ULL}, {0x0ULL, 0x0ULL}, 0xFFE0000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFF00000000ULL}, {0x0ULL, 0x0ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0xFEFEFEFEFEFEFEFEULL, 0xFFFFFFFF00000007ULL}, {0x101010101010101ULL, 0x0ULL}, 0xFEFEFEFEFEFEFEFEULL, 0x100000000000000ULL},
  {64u, {0xFFFFFFFF000000FFULL, 0x0ULL}, {0x80000000ULL, 0x0ULL}, 0xFFFFFFFF000000FFULL, 0x0ULL},
  {64u, {0xFFE0000000000000ULL, 0x0ULL}, {0x10000000000000ULL, 0x0ULL}, 0xFFE0000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFF00000000ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x7ULL}, 0x7FULL, 0x8000000000000000ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[2], inO[2];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 2; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
