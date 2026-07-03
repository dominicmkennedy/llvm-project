namespace SubNsw_arg0_Smin_arg0_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFFFF8ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0xFFFFFF20ULL, 0x80000000ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xF8000000ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0xF8000000ULL, 0x0ULL},
  {32u, {0xFF000000ULL, 0xFFFFFFF0ULL}, {0x0ULL, 0x0ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0xFFFFE000ULL, 0x80000000ULL}, {0x0ULL, 0x0ULL}, 0xFFFFE000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x4ULL}, 0xFFFFFFFF80000000ULL, 0x0ULL},
  {64u, {0x4ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x3ULL, 0x8ULL}, 0x8000000000000004ULL, 0x0ULL},
  {64u, {0x1ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x6ULL, 0x8ULL}, 0x8000000000000001ULL, 0x0ULL},
  {64u, {0x3ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x4ULL, 0x8ULL}, 0x8000000000000003ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFE0ULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x4ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
  {64u, {0x5ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x2ULL, 0x8ULL}, 0x8000000000000005ULL, 0x0ULL},
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
