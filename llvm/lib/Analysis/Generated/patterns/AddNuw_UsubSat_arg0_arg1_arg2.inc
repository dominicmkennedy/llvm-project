namespace AddNuw_UsubSat_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x80000000ULL, 0xFFFFFFFCULL, 0xFFFFFFFEULL}, {0x0ULL, 0x3ULL, 0x1ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFF8ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x7ULL, 0x3ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x2ULL, 0x1ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFE7ULL, 0xFFFFFFF4ULL}, {0x0ULL, 0x18ULL, 0xBULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFE6ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0x19ULL, 0xCULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFE0ULL, 0xFFFFFFF0ULL}, {0x0ULL, 0x1FULL, 0xFULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFCAULL, 0xFFFFFFE5ULL}, {0x0ULL, 0x35ULL, 0x1AULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFF0ULL, 0xFFFFFFF8ULL}, {0x0ULL, 0xFULL, 0x7ULL}, 0x80000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFC0ULL, 0xFFFFFFFFFFFFFFE0ULL}, {0x0ULL, 0x3FULL, 0x1FULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFF0ULL, 0xFFFFFFFFFFFFFFF8ULL}, {0x0ULL, 0xFULL, 0x7ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFF7FFFFFFFULL, 0xFFFFFFFFC0000000ULL}, {0x0ULL, 0x80000000ULL, 0x3FFFFFFFULL}, 0x8000000000000000ULL, 0x0ULL},
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
