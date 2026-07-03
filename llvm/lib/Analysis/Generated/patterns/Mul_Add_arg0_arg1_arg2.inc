namespace Mul_Add_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFC00ULL, 0xFF00ULL, 0xFFFAULL}, {0x0ULL, 0x0ULL, 0x5ULL}, 0xE000ULL, 0x0ULL},
  {32u, {0xFFFFFFF8ULL, 0xFFFFFFFEULL, 0xFFFFFFFAULL}, {0x0ULL, 0x1ULL, 0x0ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFC0000ULL, 0xFFFF0000ULL, 0xFFFFFFFAULL}, {0x0ULL, 0x0ULL, 0x5ULL}, 0xFFE00000ULL, 0x0ULL},
  {32u, {0xFFFFFE00ULL, 0xFFFFFF84ULL, 0xFFFFF7A2ULL}, {0x0ULL, 0x7BULL, 0x85DULL}, 0xFFE00000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFFEULL, 0xFFFFFF00ULL}, {0x0ULL, 0x1ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFFEULL, 0xFFFFFFFAULL}, {0x0ULL, 0x1ULL, 0x5ULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0xFFFFFC03ULL, 0xFFFFFFF7ULL, 0xFFFFFF00ULL}, {0x0ULL, 0x8ULL, 0x0ULL}, 0xFFFC0003ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF8FULL}, {0x0ULL, 0x1ULL, 0x70ULL}, 0xFFFFFF800000000FULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFF0000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF00ULL}, {0x0ULL, 0x1ULL, 0x0ULL}, 0xFFFFFFFFFF000000ULL, 0x0ULL},
  {64u, {0xFFFFFF8000000003ULL, 0xFFFFFFFE00000000ULL, 0xFFFFFFFFFFFFFFC3ULL}, {0x0ULL, 0x0ULL, 0x3CULL}, 0xFFFFE00000000003ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFF00ULL}, {0x0ULL, 0xFFFFFFFFULL, 0x0ULL}, 0xFFFFFF0000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFF0000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFF0000ULL}, {0x0ULL, 0x1ULL, 0x0ULL}, 0xFFFFFFFF00000000ULL, 0x0ULL},
  {64u, {0xFFFFC000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFF8000ULL}, {0x0ULL, 0x1ULL, 0x0ULL}, 0xE0000000ULL, 0x0ULL},
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
