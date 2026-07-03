namespace AddNsw_MulNswNuw_AddNswNuw_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x80000000ULL, 0xFFFFFFFEULL, 0xFFFFFFF7ULL, 0x1ULL}, {0x0ULL, 0x1ULL, 0x8ULL, 0xFFFFFFFEULL}, 0x80000001ULL, 0x6ULL},
  {32u, {0xFFFFFE00ULL, 0xFFFFFFFEULL, 0xFFFFFFF7ULL, 0x7ULL}, {0x0ULL, 0x1ULL, 0x8ULL, 0xFFFFFFF8ULL}, 0xFFFFF007ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFEULL, 0xFFFFFFF5ULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0xAULL, 0xFFFFFFFFULL}, 0x80000000ULL, 0x1ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFEULL, 0xFFFFFFFDULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0x2ULL, 0xFFFFFFFFULL}, 0x80000000ULL, 0x1ULL},
  {32u, {0xFFFFFFC0ULL, 0xFFFFFF81ULL, 0xFFFFFFF5ULL, 0x1DFULL}, {0x30ULL, 0x0ULL, 0xAULL, 0xFFFFFE20ULL}, 0xFFFFF801ULL, 0x0ULL},
  {32u, {0xFFFFFFC0ULL, 0xFFFFFF01ULL, 0xFFFFFFF5ULL, 0x1DFULL}, {0x30ULL, 0x0ULL, 0xAULL, 0xFFFFFE20ULL}, 0xFFFFF001ULL, 0x0ULL},
  {32u, {0xFFFFFF01ULL, 0xFFFFFFC0ULL, 0xFFFFFFF5ULL, 0x1DFULL}, {0x0ULL, 0x30ULL, 0xAULL, 0xFFFFFE20ULL}, 0xFFFFF001ULL, 0x0ULL},
  {32u, {0x1ULL, 0xFFFFFFC0ULL, 0xFFFFFFF5ULL, 0x1DFULL}, {0x0ULL, 0x30ULL, 0xAULL, 0xFFFFFE20ULL}, 0x80000001ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFFDULL, 0xFFFFFFF7ULL, 0x3ULL}, {0x0ULL, 0x2ULL, 0x8ULL, 0xFFFFFFFCULL}, 0xFFFFF003ULL, 0x4ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFF7ULL, 0x3ULL}, {0x0ULL, 0x2ULL, 0x8ULL, 0xFFFFFFFCULL}, 0x80000003ULL, 0x4ULL},
  {32u, {0xFFFFFFE0ULL, 0xFFFFFFFEULL, 0xFFFFFFF5ULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0xAULL, 0xFFFFFFFFULL}, 0xFFFFFE00ULL, 0x1ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFFDULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0x2ULL, 0xFFFFFFFFFFFFFFFFULL}, 0x8000000000000000ULL, 0x1ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF8FULL, 0x6FULL}, {0x0ULL, 0x1ULL, 0x70ULL, 0xFFFFFFFFFFFFFF90ULL}, 0xFFFFFF800000000FULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF8FULL, 0x6FULL}, {0x0ULL, 0x1ULL, 0x70ULL, 0xFFFFFFFFFFFFFF90ULL}, 0x800000000000000FULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFF5ULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0xAULL, 0xFFFFFFFFFFFFFFFFULL}, 0x8000000000000000ULL, 0x1ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[4], inO[4];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  inZ[3] = ssa_3[0].getZExtValue();
  inO[3] = ssa_3[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 4; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
