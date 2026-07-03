namespace AddNswNuw_MulNswNuw_arg0_arg1_Udiv_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFC00000ULL, 0xFFFFFF7DULL, 0x0ULL, 0xFFFFFFF5ULL}, {0x0ULL, 0x82ULL, 0x0ULL, 0xAULL}, 0xC0000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFF800ULL, 0xFFFFFFFF05F5E0FFULL, 0x0ULL, 0xFFFFFFFFFA0A1EFFULL}, {0x0ULL, 0xFA0A1F00ULL, 0x0ULL, 0x5F5E100ULL}, 0xFFFFF80000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFC00ULL, 0xFFFFFFFF05F5E0FFULL, 0x8000000000000000ULL, 0xFFFFFFFFFA0A1EFFULL}, {0x0ULL, 0xFA0A1F00ULL, 0x0ULL, 0x5F5E100ULL}, 0xFFFFFC0000000000ULL, 0x0ULL},
  {64u, {0xFFF0000000000000ULL, 0xFFFFFFFFFFFFFF9BULL, 0xFFFFFFFFFFFFF000ULL, 0xFFFFFFFFFFFFFFC3ULL}, {0x0ULL, 0x64ULL, 0x0ULL, 0x3CULL}, 0xF800000000000000ULL, 0x0ULL},
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
