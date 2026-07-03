namespace Select_ICmpEq_arg0_arg1_arg0_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0x0ULL, 0xFEULL, 0xFDULL}, {0x0ULL, 0x1ULL, 0x2ULL}, 0xFCULL, 0x0ULL},
  {8u, {0x0ULL, 0xFEULL, 0xFAULL}, {0x0ULL, 0x1ULL, 0x5ULL}, 0xFAULL, 0x1ULL},
  {8u, {0x0ULL, 0xFFULL, 0xFAULL}, {0x0ULL, 0x0ULL, 0x5ULL}, 0xFAULL, 0x0ULL},
  {8u, {0xFEULL, 0xFFULL, 0xFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFULL, 0x0ULL},
  {8u, {0x0ULL, 0xF5ULL, 0xF2ULL}, {0x0ULL, 0xAULL, 0xDULL}, 0xF0ULL, 0x8ULL},
  {16u, {0x0ULL, 0xFFF2ULL, 0xFFFEULL}, {0x0ULL, 0xDULL, 0x1ULL}, 0xFFF2ULL, 0x1ULL},
  {32u, {0x0ULL, 0xAAAAAAAAULL, 0xAAAAAAABULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xAAAAAAAAULL, 0x0ULL},
  {32u, {0x0ULL, 0x80000000ULL, 0xAAAAAAABULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFFULL}, {0x0ULL, 0x2ULL, 0x0ULL}, 0xFFFFFFFDULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x2ULL, 0x1ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFEULL, 0x0ULL},
  {32u, {0xC46535FFULL, 0xFFFFFFFFULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL, 0x0ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFFEULL, 0x0ULL},
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
