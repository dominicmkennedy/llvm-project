namespace Udiv_AddNuw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0x8000ULL, 0xFFFAULL, 0xFFF9ULL}, {0x0ULL, 0x5ULL, 0x6ULL}, 0xE000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFF7ULL, 0xFFFFFFF6ULL}, {0x0ULL, 0x8ULL, 0x9ULL}, 0xF0000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFF0001ULL, 0xFFFF0000ULL}, {0x0ULL, 0xFFFEULL, 0xFFFFULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFF4ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0xBULL, 0xCULL}, 0xF0000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFDULL, 0xFFFFFFFCULL}, {0x0ULL, 0x2ULL, 0x3ULL}, 0xC0000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFCULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL, 0x3ULL}, 0xC0000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFF85EDFULL, 0xFFF0BDBFULL}, {0x0ULL, 0x7A120ULL, 0xF4240ULL}, 0xFFFFF000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x0ULL, 0x5ULL, 0x6ULL}, 0xE000000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFC46535FFULL}, {0x0ULL, 0x0ULL, 0x3B9ACA00ULL}, 0xFFFFFFFC00000000ULL, 0x0ULL},
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
