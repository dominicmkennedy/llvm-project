namespace AddNsw_Select_ICmpSlt_arg0_arg1_arg2_arg3_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xA0ULL, 0xB1ULL, 0x33ULL, 0x4DULL}, {0x40ULL, 0x4EULL, 0xCCULL, 0xB2ULL}, 0xE0ULL, 0x0ULL},
  {8u, {0x80ULL, 0x91ULL, 0x53ULL, 0x6DULL}, {0x60ULL, 0x6EULL, 0xACULL, 0x92ULL}, 0xE0ULL, 0x0ULL},
  {32u, {0xFFFFFCC0ULL, 0xFFFFFCDFULL, 0x2FFULL, 0x31FULL}, {0x300ULL, 0x320ULL, 0xFFFFFD00ULL, 0xFFFFFCE0ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFF8ULL, 0xFFFFFFF9ULL, 0xFFFFFFFEULL, 0x5ULL}, {0x0ULL, 0x6ULL, 0x1ULL, 0xFFFFFFFAULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFC0ULL, 0xFFFFFFFFFFFFFFC9ULL, 0xFFFFFFFFFFFFFFFEULL, 0x35ULL}, {0x0ULL, 0x36ULL, 0x1ULL, 0xFFFFFFFFFFFFFFCAULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
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
