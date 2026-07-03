namespace AddNsw_AddNswNuw_arg0_arg1_MulNsw_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x800001FFULL, 0xFDFDFFFFULL, 0xFFFFFF00ULL, 0x97DBULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFF6824ULL}, 0x80000003ULL, 0x0ULL},
  {32u, {0x8000007FULL, 0xFDFDFFFFULL, 0xFFFFFC03ULL, 0x5E33ULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFFA1CCULL}, 0x8000000FULL, 0x0ULL},
  {32u, {0xFFFE0000ULL, 0xFFFE0BFFULL, 0xFFFFFF00ULL, 0x93ULL}, {0x0ULL, 0x1F400ULL, 0x0ULL, 0xFFFFFF6CULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0xFE0001FFULL, 0xFDFDFFFFULL, 0xFFFFFC03ULL, 0x5E33ULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFFA1CCULL}, 0xF800000FULL, 0x0ULL},
  {32u, {0x8000007FULL, 0xFDFDFFFFULL, 0xFFFFFC01ULL, 0x5E33ULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFFA1CCULL}, 0x80000007ULL, 0x0ULL},
  {32u, {0xFFFE0000ULL, 0xFFFE0BFFULL, 0xFFFFFF00ULL, 0x16FULL}, {0x0ULL, 0x1F400ULL, 0x0ULL, 0xFFFFFE90ULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0xFE0000FFULL, 0xFDFDFFFFULL, 0xFFFFFC01ULL, 0x5E33ULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFFA1CCULL}, 0xF8000007ULL, 0x0ULL},
  {32u, {0x800001FFULL, 0xFDFDFFFFULL, 0xFFFFFF00ULL, 0x178CFULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFE8730ULL}, 0x8000000FULL, 0x0ULL},
  {32u, {0xFE0001FFULL, 0xFDFDFFFFULL, 0xFFFFFF00ULL, 0x97DBULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFF6824ULL}, 0xF8000003ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFE0BFFULL, 0xFFFFFF00ULL, 0x93ULL}, {0x0ULL, 0x1F400ULL, 0x0ULL, 0xFFFFFF6CULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFE00007FULL, 0xFDFDFFFFULL, 0xFFFFFC00ULL, 0x5E33ULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFFA1CCULL}, 0xF8000003ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFE0BFFULL, 0xFFFFFF00ULL, 0x16FULL}, {0x0ULL, 0x1F400ULL, 0x0ULL, 0xFFFFFE90ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFE0001FFULL, 0xFDFDFFFFULL, 0xFFFFFF00ULL, 0x178CFULL}, {0x0ULL, 0x2020000ULL, 0x0ULL, 0xFFFE8730ULL}, 0xF800000FULL, 0x0ULL},
  {64u, {0xFFF8000000000000ULL, 0xFFF0000000000026ULL, 0xFFFFFFFFFFFFE000ULL, 0x12ULL}, {0x0ULL, 0xFFFFFFFFFFFD9ULL, 0x0ULL, 0xFFFFFFFFFFFFFFEDULL}, 0xFFE0000000000000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[4], inO[4];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  inZ[3] = ssa_3[0].getZExtValue();
  inO[3] = ssa_3[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 4; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
