namespace And_AddNswNuw_arg0_arg1_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFF80ULL, 0xFF80ULL}, {0x0ULL, 0x7FULL}, 0xFF81ULL, 0x0ULL},
  {16u, {0x0ULL, 0xFF80ULL}, {0x0ULL, 0x7FULL}, 0x1ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL}, 0x1ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFF0000ULL}, {0x0ULL, 0xFFFFULL}, 0xFFFF0001ULL, 0x0ULL},
  {32u, {0xFF0000FFULL, 0xFF000000ULL}, {0x0ULL, 0xFFFFFFULL}, 0xFF0001FFULL, 0x0ULL},
  {32u, {0xFFFE0000ULL, 0xFFFE0000ULL}, {0x0ULL, 0x1FFFFULL}, 0xFFFE0001ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL}, 0x80000001ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFFC0ULL}, {0x0ULL, 0x3FULL}, 0xFFFF0001ULL, 0x0ULL},
  {32u, {0xFFFFFFC1ULL, 0xFFFFFFC0ULL}, {0x0ULL, 0x3FULL}, 0xFFFFFFC3ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFE0000ULL}, {0x0ULL, 0x1FFFFULL}, 0x1ULL, 0x0ULL},
  {32u, {0xFFFE00FFULL, 0xFFFE0000ULL}, {0x0ULL, 0x1FFFFULL}, 0xFFFE01FFULL, 0x0ULL},
  {32u, {0xFF0000FFULL, 0xFFFE0000ULL}, {0x0ULL, 0x1FFFFULL}, 0xFF0001FFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x1ULL, 0x1ULL}, 0x3ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL}, {0x0ULL, 0xFFFFFFFFULL}, 0xFFFFFFFF00000001ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x80000001ULL, 0x1ULL}, 0xFFFFFFFF00000003ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[2], inO[2];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 2; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
