namespace Udiv_arg0_Umax_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFAC3ULL}, {0x0ULL, 0x0ULL, 0x53CULL}, 0xFFC0000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFF7FFFULL}, {0x0ULL, 0x0ULL, 0x8000ULL}, 0xFFFE000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFBFFULL}, {0x0ULL, 0x0ULL, 0x400ULL}, 0xFFC0000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFFDULL}, {0xFFFFFFFFULL, 0x0ULL, 0x2ULL}, 0xFFFFFFFF80000000ULL, 0x0ULL},
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
