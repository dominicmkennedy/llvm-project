namespace Select_ICmpUlt_arg0_Add_arg1_arg2_arg3_Add_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xC0ULL, 0x0ULL, 0xFEULL, 0xFFULL}, {0x3FULL, 0x0ULL, 0x1ULL, 0x0ULL}, 0xC0ULL, 0x0ULL},
  {8u, {0xE3ULL, 0x0ULL, 0xFEULL, 0xDFULL}, {0x1CULL, 0x0ULL, 0x1ULL, 0x20ULL}, 0xC0ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x0ULL, 0x1ULL, 0xFFFF0000ULL}, {0xFFFFULL, 0x0ULL, 0xFFFFFFFEULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF84ULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFFFULL}, {0x7BULL, 0x0ULL, 0x1ULL, 0x0ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0xFFFFE001ULL, 0xFFFFFFFEULL, 0x0ULL, 0xFFFFE001ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFE000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x0ULL, 0xFULL, 0xFFFF0000ULL}, {0xFFFFULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFFC0ULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL}, {0x3FULL, 0x0ULL, 0x1ULL, 0x1ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFFE001ULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFE001ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFE000ULL, 0x0ULL},
  {32u, {0xFFFFFF01ULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFFF01ULL}, {0xFEULL, 0x0ULL, 0x1ULL, 0xFEULL}, 0xFFFFFF00ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFF5ULL, 0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFFF5ULL}, {0xAULL, 0x0ULL, 0x0ULL, 0xAULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFEFFFFULL, 0x0ULL, 0x0ULL, 0xFFFFFFFFFFFEFFFFULL}, {0x10000ULL, 0x0ULL, 0x0ULL, 0x10000ULL}, 0xFFFFFFFFFFFE0000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFF4ULL, 0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFFF4ULL}, {0xBULL, 0x0ULL, 0x0ULL, 0xBULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFF80C9ULL, 0xFFFFF80000000000ULL, 0xFFFFFFFFFFFFFFF9ULL, 0xFFFFFFFFFFFF80C9ULL}, {0x7F36ULL, 0x0ULL, 0x0ULL, 0x7F36ULL}, 0xFFFFFFFFFFFF8000ULL, 0x0ULL},
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
