namespace Select_ICmpUlt_Select_ICmpUlt_arg0_arg1_ShlNuw_arg0_arg2_arg0_arg3_OrDisjoint_Select_ICmpUlt_arg0_arg1_arg4_arg5_arg6_Select_ICmpUlt_arg0_arg1_arg4_arg5 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[7], argO[7], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xEFFFFFFFULL, 0xFFFFFFFBULL, 0xBFFFFFFFULL, 0x0ULL, 0x0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x10000000ULL, 0x4ULL, 0x40000000ULL, 0x4ULL, 0x0ULL, 0x2ULL}, 0x0ULL, 0x4ULL},
  {32u, {0x0ULL, 0xFFFEFFFFULL, 0xFFFFFFEFULL, 0xFEFFFFFFULL, 0xFFFFFFEFULL, 0xFFFFFFFFULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x10000ULL, 0x10ULL, 0x1000000ULL, 0x10ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFE7ULL, 0x10ULL},
  {32u, {0x0ULL, 0xFEFFFFFFULL, 0xFFFFFFF7ULL, 0xEFFFFFFFULL, 0xFFFFFFE7ULL, 0xFFFFFFEFULL, 0xFFFFFFFBULL}, {0x0ULL, 0x1000000ULL, 0x8ULL, 0x10000000ULL, 0x8ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFE3ULL, 0x8ULL},
  {32u, {0x0ULL, 0xEFFFFFFFULL, 0xFFFFFFFBULL, 0xBFFFFFFFULL, 0xFFFFFFE3ULL, 0xFFFFFFE7ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x10000000ULL, 0x4ULL, 0x40000000ULL, 0x4ULL, 0x0ULL, 0x2ULL}, 0xFFFFFFE1ULL, 0x4ULL},
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
