namespace AddNsw_MulNsw_Udiv_arg0_arg1_arg2_Udiv_arg0_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFA0A1EFFULL, 0x270FULL, 0xFFFFD8EFULL}, {0x0ULL, 0x5F5E100ULL, 0xFFFFD8F0ULL, 0x2710ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0xFFFFFC00ULL, 0xFFFFFF69ULL, 0x18ULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x96ULL, 0xFFFFFFE7ULL, 0x6ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFF000000ULL, 0xFFFFC387ULL, 0x2AULL, 0xFFFFFE97ULL}, {0x0ULL, 0x3C78ULL, 0xFFFFFFD5ULL, 0x168ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFFFFE000000000ULL, 0xFFFFFFFF296C5BFFULL, 0x3BULL, 0xFFFFFFFFFC6C78FFULL}, {0x0ULL, 0xD693A400ULL, 0xFFFFFFFFFFFFFFC4ULL, 0x3938700ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFF800000000000ULL, 0xFFFFFCB9CF475FFFULL, 0x3BULL, 0xFFFFFFF207B8A7FFULL}, {0x0ULL, 0x34630B8A000ULL, 0xFFFFFFFFFFFFFFC4ULL, 0xDF8475800ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
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
