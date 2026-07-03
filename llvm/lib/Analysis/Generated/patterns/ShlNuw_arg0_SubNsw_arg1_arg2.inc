namespace ShlNuw_arg0_SubNsw_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFFFEULL, 0xFFF2ULL, 0xFFF0ULL}, {0x0ULL, 0xDULL, 0x0ULL}, 0xC000ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFE8ULL, 0x80000000ULL}, {0x0ULL, 0x17ULL, 0x0ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFFAULL, 0x80000000ULL}, {0x0ULL, 0x5ULL, 0x0ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFFFULL, 0x0ULL}, {0x1ULL, 0x0ULL, 0x80000000ULL}, 0x1ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFFCULL, 0x80000000ULL}, {0x0ULL, 0x3ULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF7ULL, 0x80000000ULL}, {0x1ULL, 0x8ULL, 0x0ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF8ULL, 0x80000000ULL}, {0x1ULL, 0x7ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF9ULL, 0x80000000ULL}, {0x1ULL, 0x6ULL, 0x0ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF0ULL, 0x80000000ULL}, {0x1ULL, 0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFE7ULL, 0xFFFFFFE3ULL}, {0x1ULL, 0x18ULL, 0x0ULL}, 0xFEEEEEEEULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF6ULL, 0xFFFFFFF0ULL}, {0x1ULL, 0x9ULL, 0x0ULL}, 0xFFFFFC00ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFF8ULL, 0x8000000000000001ULL}, {0x1ULL, 0x7ULL, 0x0ULL}, 0xFFFFFFFFFFFFFF55ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL}, {0x1ULL, 0x0ULL, 0x8000000000000000ULL}, 0x1ULL, 0x0ULL},
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
