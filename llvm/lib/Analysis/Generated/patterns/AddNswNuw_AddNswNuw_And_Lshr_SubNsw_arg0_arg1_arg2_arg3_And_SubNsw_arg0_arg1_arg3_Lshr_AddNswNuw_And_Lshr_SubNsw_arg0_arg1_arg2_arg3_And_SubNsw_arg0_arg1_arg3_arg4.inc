namespace AddNswNuw_AddNswNuw_And_Lshr_SubNsw_arg0_arg1_arg2_arg3_And_SubNsw_arg0_arg1_arg3_Lshr_AddNswNuw_And_Lshr_SubNsw_arg0_arg1_arg2_arg3_And_SubNsw_arg0_arg1_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFF0000ULL, 0xFFFFAAAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL, 0x4ULL}, 0x93330000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL, 0x4ULL}, 0x93333300ULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0xFFFFFFFEULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL, 0x4ULL}, 0x93333330ULL, 0x0ULL},
  {32u, {0xF0000000ULL, 0xFAAAAAAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL, 0x4ULL}, 0x90000000ULL, 0x0ULL},
  {32u, {0xFFFFFC00ULL, 0xFFFFFEAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL, 0x4ULL}, 0x93333000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFAAAAAAAAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL, 0x4ULL}, 0x9333333300000000ULL, 0x0ULL},
  {64u, {0xFFFF0000FFFF0000ULL, 0xFFFFAAAAFFFFAAAAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL, 0x4ULL}, 0x9333000003330000ULL, 0x0ULL},
  {64u, {0xFF00FF00FF00FF00ULL, 0xFFAAFFAAFFAAFFAAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL, 0x4ULL}, 0x9300030003000300ULL, 0x0ULL},
  {64u, {0xF0F0F0F0F0F0F0F0ULL, 0xFAFAFAFAFAFAFAFAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL, 0x4ULL}, 0x9000000000000000ULL, 0x0ULL},
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
