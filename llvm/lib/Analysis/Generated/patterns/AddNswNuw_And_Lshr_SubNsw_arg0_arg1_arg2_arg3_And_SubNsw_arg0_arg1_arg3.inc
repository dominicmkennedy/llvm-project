namespace AddNswNuw_And_Lshr_SubNsw_arg0_arg1_arg2_arg3_And_SubNsw_arg0_arg1_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFF0000ULL, 0xFFFFAAAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL}, 0x99998888ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL}, 0x99999988ULL, 0x0ULL},
  {32u, {0xFFFFFFF0ULL, 0xFFFFFFFAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL}, 0x99999998ULL, 0x0ULL},
  {32u, {0xF0000000ULL, 0xFAAAAAAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL}, 0x98888888ULL, 0x0ULL},
  {32u, {0xFFFFFC00ULL, 0xFFFFFEAAULL, 0xFFFFFFFDULL, 0xCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x33333333ULL}, 0x99999888ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFAAAAAAAAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL}, 0x9999999988888888ULL, 0x0ULL},
  {64u, {0xFFFF0000FFFF0000ULL, 0xFFFFAAAAFFFFAAAAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL}, 0x9999888899998888ULL, 0x0ULL},
  {64u, {0xFF00FF00FF00FF00ULL, 0xFFAAFFAAFFAAFFAAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL}, 0x9988998899889988ULL, 0x0ULL},
  {64u, {0xF0F0F0F0F0F0F0F0ULL, 0xFAFAFAFAFAFAFAFAULL, 0xFFFFFFFFFFFFFFFDULL, 0xCCCCCCCCCCCCCCCCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3333333333333333ULL}, 0x9898989898989898ULL, 0x0ULL},
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
