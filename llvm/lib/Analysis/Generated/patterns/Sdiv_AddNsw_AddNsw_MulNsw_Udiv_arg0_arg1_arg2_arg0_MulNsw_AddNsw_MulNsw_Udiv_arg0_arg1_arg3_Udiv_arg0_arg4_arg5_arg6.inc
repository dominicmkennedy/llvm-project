namespace Sdiv_AddNsw_AddNsw_MulNsw_Udiv_arg0_arg1_arg2_arg0_MulNsw_AddNsw_MulNsw_Udiv_arg0_arg1_arg3_Udiv_arg0_arg4_arg5_arg6 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[7], argO[7], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0xFFFFFFE000000000ULL, 0xFFFFFFFF296C5BFFULL, 0xD693A3FFULL, 0x3BULL, 0xFFFFFFFFFC6C78FFULL, 0x39386FFULL, 0xFFFFFFFFFFF0BDBFULL}, {0x0ULL, 0xD693A400ULL, 0xFFFFFFFF296C5C00ULL, 0xFFFFFFFFFFFFFFC4ULL, 0x3938700ULL, 0xFFFFFFFFFC6C7900ULL, 0xF4240ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFF800000000000ULL, 0xFFFFFCB9CF475FFFULL, 0x34630B89FFFULL, 0x3BULL, 0xFFFFFFF207B8A7FFULL, 0xDF84757FFULL, 0xFFFFFFFFC46535FFULL}, {0x0ULL, 0x34630B8A000ULL, 0xFFFFFCB9CF476000ULL, 0xFFFFFFFFFFFFFFC4ULL, 0xDF8475800ULL, 0xFFFFFFF207B8A800ULL, 0x3B9ACA00ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4, std::array<APInt, 2> ssa_5, std::array<APInt, 2> ssa_6) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64 || ssa_5[0].getBitWidth() > 64 || ssa_6[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[7], inO[7];
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
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 7; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
