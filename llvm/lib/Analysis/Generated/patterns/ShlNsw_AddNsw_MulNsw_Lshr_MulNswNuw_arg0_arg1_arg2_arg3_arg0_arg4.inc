namespace ShlNsw_AddNsw_MulNsw_Lshr_MulNswNuw_arg0_arg1_arg2_arg3_arg0_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFC000ULL, 0xFFFFEB84ULL, 0xFFFFFFECULL, 0x63ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x147BULL, 0x13ULL, 0xFFFFFF9CULL, 0x1ULL}, 0xFFFFFF01ULL, 0x0ULL},
  {32u, {0xFFFFF800ULL, 0xFFFFD709ULL, 0xFFFFFFEBULL, 0x63ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x28F6ULL, 0x14ULL, 0xFFFFFF9CULL, 0x10ULL}, 0xFF80FFFFULL, 0x0ULL},
  {32u, {0xFFFFFFC0ULL, 0xFFFFFF98ULL, 0xFFFFFFF5ULL, 0x9ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x67ULL, 0xAULL, 0xFFFFFFF6ULL, 0x8ULL}, 0xFFFFF0FFULL, 0x0ULL},
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
