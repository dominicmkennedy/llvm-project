namespace Select_ICmpUlt_Select_arg0_arg1_arg2_arg3_Select_arg0_arg1_arg2_Lshr_Select_arg0_arg1_arg2_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0x0ULL, 0x0ULL, 0xF0ULL, 0xFBULL, 0xFDULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x4ULL, 0x2ULL}, 0xC0ULL, 0x0ULL},
  {16u, {0x0ULL, 0xFF00ULL, 0xFFF0ULL, 0xFFFBULL, 0xFFFDULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x4ULL, 0x2ULL}, 0xFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF0000ULL, 0xFFFFFF00ULL, 0xFFFFFFEFULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x10ULL, 0x4ULL}, 0xFFFFF000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFF0000ULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFEFULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x10ULL, 0x4ULL}, 0xFFFFFFFFFFFFF000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[5], inO[5];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  inZ[3] = ssa_3[0].getZExtValue();
  inO[3] = ssa_3[1].getZExtValue();
  inZ[4] = ssa_4[0].getZExtValue();
  inO[4] = ssa_4[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 5; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
