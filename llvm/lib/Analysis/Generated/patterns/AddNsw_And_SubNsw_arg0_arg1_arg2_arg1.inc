namespace AddNsw_And_SubNsw_arg0_arg1_arg2_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0x3ULL}, 0x3ULL, 0x0ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFF0ULL}, {0x0ULL, 0x0ULL, 0xFULL}, 0xFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0x0ULL, 0x1ULL}, {0x1ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, 0xFFFFFFFFFFFFFFFEULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFCULL, 0x0ULL, 0x1ULL}, {0x3ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, 0xFFFFFFFFFFFFFFFCULL, 0x2ULL},
  {64u, {0xFFFFFFFFFFFFFFFCULL, 0x0ULL, 0xE000000000000001ULL}, {0x3ULL, 0x0ULL, 0x1FFFFFFFFFFFFFFEULL}, 0x1FFFFFFFFFFFFFFCULL, 0x2ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFE00ULL}, {0x0ULL, 0x0ULL, 0x1FFULL}, 0x1FFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFBULL, 0x0ULL, 0x1ULL}, {0x4ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFCULL, 0x0ULL, 0x3ULL}, {0x3ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFCULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFDULL, 0x0ULL, 0x1ULL}, {0x2ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFF9ULL, 0x0ULL, 0x1ULL}, {0x6ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x4ULL},
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
