namespace AddNswNuw_Udiv_Shl_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFCULL, 0xFFFFFF9BULL, 0xFFFFFFFBULL}, {0x0ULL, 0x3ULL, 0x64ULL, 0x4ULL}, 0xFC000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFF5ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL, 0xAULL, 0x1ULL}, 0xE0000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFF9CULL}, {0x0ULL, 0x1ULL, 0x28ULL, 0x63ULL}, 0xF800000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFB9ULL, 0xFFFFFFFFFFFFFF9CULL}, {0x0ULL, 0x1ULL, 0x46ULL, 0x63ULL}, 0xFC00000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFF9BULL}, {0x0ULL, 0x1ULL, 0x28ULL, 0x64ULL}, 0xF800000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFB9ULL, 0xFFFFFFFFFFFFFF9BULL}, {0x0ULL, 0x1ULL, 0x46ULL, 0x64ULL}, 0xFC00000000000000ULL, 0x0ULL},
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
