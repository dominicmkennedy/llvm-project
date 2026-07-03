namespace MulNsw_MulNsw_arg0_arg1_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF5ULL}, {0x0ULL, 0xAULL}, 0x80000005ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF6ULL}, {0x0ULL, 0x9ULL}, 0x80000002ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x6ULL}, 0x80000001ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFBFFULL}, {0x0ULL, 0x400ULL}, 0x80000BFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE1ULL}, {0x0ULL, 0x1EULL}, 0x80000001ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE4ULL}, {0x0ULL, 0x1BULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0xCULL}, 0x80000003ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFD8ULL}, {0x0ULL, 0x27ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0x80000005ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL}, {0x0ULL, 0x7ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFBULL}, {0x0ULL, 0x4ULL}, 0x8000000BULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFC17ULL}, {0x0ULL, 0x3E8ULL}, 0x80000017ULL, 0x0ULL},
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
