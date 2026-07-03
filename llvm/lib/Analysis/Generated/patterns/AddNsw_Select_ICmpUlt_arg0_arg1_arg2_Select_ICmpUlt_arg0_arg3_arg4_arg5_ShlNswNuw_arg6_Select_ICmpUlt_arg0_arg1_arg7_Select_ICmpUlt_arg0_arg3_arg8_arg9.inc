namespace AddNsw_Select_ICmpUlt_arg0_arg1_arg2_Select_ICmpUlt_arg0_arg3_arg4_arg5_ShlNswNuw_arg6_Select_ICmpUlt_arg0_arg1_arg7_Select_ICmpUlt_arg0_arg3_arg8_arg9 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[10], argO[10], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x80000000ULL, 0xFFFFFFBCULL, 0xFULL, 0xFFFFFF44ULL, 0xE7FULL, 0xB7FFFULL, 0x80000000ULL, 0xFFFFFFFCULL, 0xFFFFFFF9ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0x43ULL, 0xFFFFFFF0ULL, 0xBBULL, 0xFFFFF180ULL, 0xFFF48000ULL, 0x0ULL, 0x3ULL, 0x6ULL, 0xCULL}, 0x7ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4, std::array<APInt, 2> ssa_5, std::array<APInt, 2> ssa_6, std::array<APInt, 2> ssa_7, std::array<APInt, 2> ssa_8, std::array<APInt, 2> ssa_9) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64 || ssa_5[0].getBitWidth() > 64 || ssa_6[0].getBitWidth() > 64 || ssa_7[0].getBitWidth() > 64 || ssa_8[0].getBitWidth() > 64 || ssa_9[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[10], inO[10];
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
  inZ[5] = ssa_5[0].getZExtValue();
  inO[5] = ssa_5[1].getZExtValue();
  inZ[6] = ssa_6[0].getZExtValue();
  inO[6] = ssa_6[1].getZExtValue();
  inZ[7] = ssa_7[0].getZExtValue();
  inO[7] = ssa_7[1].getZExtValue();
  inZ[8] = ssa_8[0].getZExtValue();
  inO[8] = ssa_8[1].getZExtValue();
  inZ[9] = ssa_9[0].getZExtValue();
  inO[9] = ssa_9[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 10; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
