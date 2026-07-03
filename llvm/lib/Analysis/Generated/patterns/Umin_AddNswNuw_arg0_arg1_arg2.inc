namespace Umin_AddNswNuw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF2ULL}, {0x0ULL, 0x8ULL, 0xDULL}, 0xFFFFFFF0ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF5ULL}, {0x0ULL, 0x8ULL, 0xAULL}, 0xFFFFFFF4ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF4ULL}, {0x0ULL, 0x8ULL, 0xBULL}, 0xFFFFFFF4ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF6ULL}, {0x0ULL, 0x8ULL, 0x9ULL}, 0xFFFFFFF6ULL, 0x8ULL},
  {32u, {0x7ULL, 0xFFFFFFF7ULL, 0xFFFFFFF5ULL}, {0x0ULL, 0x8ULL, 0xAULL}, 0xFFFFFFF5ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF1ULL}, {0x0ULL, 0x8ULL, 0xEULL}, 0xFFFFFFF0ULL, 0x8ULL},
  {32u, {0x7ULL, 0xFFFFFFF7ULL, 0xFFFFFFF2ULL}, {0x0ULL, 0x8ULL, 0xDULL}, 0xFFFFFFF2ULL, 0x8ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFFAULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x5ULL, 0x6ULL}, 0xFFFFFFF8ULL, 0x4ULL},
  {32u, {0x7ULL, 0xFFFFFFF7ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0x8ULL, 0xCULL}, 0xFFFFFFF3ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0x8ULL, 0xCULL}, 0xFFFFFFF0ULL, 0x8ULL},
  {32u, {0x80000007ULL, 0xFFFFFFF7ULL, 0xFFFFFFF1ULL}, {0x0ULL, 0x8ULL, 0xEULL}, 0xFFFFFFF1ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF0ULL}, {0x0ULL, 0x8ULL, 0xFULL}, 0xFFFFFFF0ULL, 0x8ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF8ULL}, {0x0ULL, 0x8ULL, 0x6ULL}, 0xFFFFFFF8ULL, 0x6ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x8ULL, 0x2ULL}, 0xFFFFFFFCULL, 0x2ULL},
  {64u, {0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x0ULL, 0x4ULL, 0x6ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x4ULL},
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
