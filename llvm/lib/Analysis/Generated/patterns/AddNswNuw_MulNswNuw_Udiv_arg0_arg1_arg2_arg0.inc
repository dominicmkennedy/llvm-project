namespace AddNswNuw_MulNswNuw_Udiv_arg0_arg1_arg2_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFF00ULL, 0xFFFFFFF5ULL, 0xFFFFFF09ULL}, {0x0ULL, 0xAULL, 0xF6ULL}, 0xFFFFE0F0ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFFF5ULL, 0xFFFFFF09ULL}, {0x0ULL, 0xAULL, 0xF6ULL}, 0xFFE000F0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFAAULL, 0xFFFFFFFFFFFFFF54ULL}, {0x0ULL, 0x55ULL, 0xABULL}, 0x8000000000000080ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFF09ULL}, {0x0ULL, 0xAULL, 0xF6ULL}, 0xFFFFFFE0000000F0ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFF0BDBFULL, 0xFFFFFFFF000F423FULL}, {0x0ULL, 0xF4240ULL, 0xFFF0BDC0ULL}, 0xFFFFE000FFF00000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[3], inO[3];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 3; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
