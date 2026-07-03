namespace Add_Select_ICmpUlt_arg0_arg1_arg2_arg1_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFD8EFULL, 0x0ULL, 0xFFFFD809ULL, 0xFFFFFFFAULL}, {0x2710ULL, 0x0ULL, 0x27F6ULL, 0x5ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0xFFFFFFE2ULL, 0x0ULL, 0xFFFFFFE2ULL, 0xFFFFFFFDULL}, {0x1DULL, 0x0ULL, 0x1DULL, 0x2ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFEFFFFULL, 0x0ULL, 0xFFFFFFFFFFFEFFFFULL, 0xFFFFFFFFFFFFFFDFULL}, {0x10000ULL, 0x0ULL, 0x10000ULL, 0x20ULL}, 0xFFFFFFFFFFFE0000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFC00ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFEULL}, {0x3FFULL, 0x0ULL, 0x0ULL, 0x1ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFEFFFFULL, 0x0ULL, 0xFFFFFFFFFFFEFFFFULL, 0xFFFFFFFF00000003ULL}, {0x10000ULL, 0x0ULL, 0x10000ULL, 0x0ULL}, 0xFFFFFFFE00000000ULL, 0x0ULL},
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
