namespace AddNswNuw_ShlNswNuw_AddNsw_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xF0ULL, 0x1ULL, 0xFDULL, 0xF4ULL}, {0x0ULL, 0xFEULL, 0x2ULL, 0xBULL}, 0xC0ULL, 0x3ULL},
  {16u, {0xFE00ULL, 0x0ULL, 0xFFFCULL, 0xF90FULL}, {0x0ULL, 0xFFFFULL, 0x3ULL, 0x6F0ULL}, 0xE007ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x23ULL, 0xFFFFFFF6ULL, 0xFFFFB7FFULL}, {0x0ULL, 0xFFFFFFDCULL, 0x9ULL, 0x4800ULL}, 0xFE0001FFULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x7FULL, 0xFFFFFFF3ULL, 0xFFE3FFFFULL}, {0x0ULL, 0xFFFFFF80ULL, 0xCULL, 0x0ULL}, 0xFFC00FFFULL, 0x0ULL},
  {32u, {0xFFFFFF80ULL, 0x2FULL, 0xFFFFFFFCULL, 0xFFFFFFC8ULL}, {0x0ULL, 0xFFFFFFD0ULL, 0x3ULL, 0x30ULL}, 0xFFFFFC00ULL, 0x0ULL},
  {32u, {0xFFFFFFF0ULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFFULL, 0x1ULL, 0x1ULL}, 0xFFFFFFE0ULL, 0x1ULL},
  {32u, {0xFFFFFFF8ULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFE0ULL}, {0x0ULL, 0xFFFFFFFFULL, 0x1ULL, 0x3ULL}, 0xFFFFFFC0ULL, 0x1ULL},
  {32u, {0xFFFFFF00ULL, 0x2FULL, 0xFFFFFFFCULL, 0xFFFFFFC8ULL}, {0x0ULL, 0xFFFFFFD0ULL, 0x3ULL, 0x30ULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0xFFFFFFE0ULL, 0x0ULL, 0xFFFFFFEFULL, 0xFFFEFFFFULL}, {0x0ULL, 0xFFFFFFFFULL, 0x10ULL, 0x10000ULL}, 0xFFE0FFFFULL, 0x0ULL},
  {32u, {0xFFFFFFF8ULL, 0x1ULL, 0xFFFFFFFEULL, 0xFFFFFFFAULL}, {0x0ULL, 0xFFFFFFFEULL, 0x1ULL, 0x5ULL}, 0xFFFFFFF0ULL, 0x1ULL},
  {32u, {0xFFFFFFF8ULL, 0x1ULL, 0xFFFFFFFEULL, 0xFFFFFFF9ULL}, {0x0ULL, 0xFFFFFFFEULL, 0x1ULL, 0x6ULL}, 0xFFFFFFE1ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0x0ULL, 0xFFFFFFFFFFFFFFF9ULL, 0xFFFFFFFFFFFFFFBFULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x6ULL, 0x40ULL}, 0xFFFFFFE00000003FULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFDULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x2ULL, 0x4ULL}, 0xFFFFFFFE00000003ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFBULL, 0xFFFFFFFFFFFFFFEFULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x4ULL, 0x10ULL}, 0xFFFFFFF80000000FULL, 0x0ULL},
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
