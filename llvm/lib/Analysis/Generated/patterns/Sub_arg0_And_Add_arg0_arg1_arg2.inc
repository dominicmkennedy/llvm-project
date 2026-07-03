namespace Sub_arg0_And_Add_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFBULL, 0xFFFFFFF0ULL}, {0x0ULL, 0x4ULL, 0xFULL}, 0x3ULL, 0xCULL},
  {32u, {0x0ULL, 0xFFFFFFBFULL, 0x3FULL}, {0x0ULL, 0x40ULL, 0xFFFFFFC0ULL}, 0x0ULL, 0xFFFFFFC0ULL},
  {32u, {0x0ULL, 0x7ULL, 0xFFFFFFF0ULL}, {0x0ULL, 0x0ULL, 0xFULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0x1FFFFFFULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFE000000ULL}, 0xFFFFFFFFFC000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0x3FFFFFULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFC00000ULL}, 0xFFFFFFFFFF800000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0x7FFULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFF800ULL}, 0xFFFFFFFFFFFFF000ULL, 0x0ULL},
  {64u, {0x7ULL, 0x0ULL, 0x1FFFFFFULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFE000000ULL}, 0xFFFFFFFFFC000007ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0x1ULL, 0x3ULL}, 0x0ULL, 0x3ULL},
  {64u, {0x0ULL, 0x3EULL, 0x1ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFC1ULL, 0xFFFFFFFFFFFFFFFEULL}, 0xFFFFFFFFFFFFFF80ULL, 0x0ULL},
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
