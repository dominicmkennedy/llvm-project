namespace Udiv_Select_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0x0ULL, 0xF3ULL, 0xE7ULL, 0xFCULL}, {0x0ULL, 0xCULL, 0x18ULL, 0x3ULL}, 0xF3ULL, 0x0ULL},
  {16u, {0x0ULL, 0xF3FFULL, 0xFCFFULL, 0xFFF9ULL}, {0x0ULL, 0xC00ULL, 0x200ULL, 0x6ULL}, 0xFD2AULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFB5C7ULL, 0xFFFFA23FULL, 0xFFFFFC17ULL}, {0x0ULL, 0x4A38ULL, 0x5DC0ULL, 0x3E8ULL}, 0xFFFFFFE4ULL, 0x10ULL},
  {32u, {0x0ULL, 0xFFFFF3FFULL, 0xFFFFFCFFULL, 0xFFFFFFF9ULL}, {0x0ULL, 0xC00ULL, 0x200ULL, 0x6ULL}, 0xFFFFFD2AULL, 0x0ULL},
  {64u, {0x0ULL, 0x7FFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFF5ULL}, {0x0ULL, 0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFFULL, 0xAULL}, 0xE222222222222222ULL, 0x888888888888888ULL},
  {64u, {0x0ULL, 0xFFFFFFFF00001FFFULL, 0xFFFFFFFF3FFFFFFFULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x0ULL, 0xFFFFE000ULL, 0xC0000000ULL, 0x6ULL}, 0xFFFFFFFFD5555AAAULL, 0x20000000ULL},
  {64u, {0x0ULL, 0xFFFFFFFF00001FFFULL, 0xFFFFFFFF3FFFFFFFULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0xFFFFE000ULL, 0xC0000000ULL, 0x3ULL}, 0xFFFFFFFFAAAAB555ULL, 0x40000000ULL},
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
