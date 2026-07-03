namespace AddNswNuw_Lshr_AddNswNuw_MulNswNuw_arg0_arg1_arg2_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFE0ULL, 0xFFFFFFF6ULL, 0xFFFFFFB6ULL, 0xFFFFFFF9ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x9ULL, 0x49ULL, 0x6ULL, 0x1ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFDF0ULL, 0xFFFFFFE8ULL, 0xFFFFFFF9ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x20FULL, 0x17ULL, 0x6ULL, 0x1ULL}, 0xFE000000ULL, 0x0ULL},
  {32u, {0xFFFFFFE0ULL, 0xFFFFFFF6ULL, 0xFFFFFFB6ULL, 0xFFFFFFF9ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x9ULL, 0x49ULL, 0x6ULL, 0x2ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFFAULL, 0xFFFFFF7DULL, 0xFFFFFFF7ULL, 0xFFFFFF1DULL}, {0x0ULL, 0x5ULL, 0x82ULL, 0x8ULL, 0xE2ULL}, 0xFFFFFF18ULL, 0xE0ULL},
  {32u, {0xFFFFF000ULL, 0xFFFFFF20ULL, 0xFFFFFF7FULL, 0xFFFFFFF7ULL, 0xFFFFFEFFULL}, {0x0ULL, 0xDFULL, 0x80ULL, 0x8ULL, 0x100ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0xFFFFFFE0ULL, 0xFFFFFB2EULL, 0xFFFFFB2EULL, 0xFFFFFFF3ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x4D1ULL, 0x4D1ULL, 0xCULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFF0000ULL, 0xFFFFFFFBULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x4ULL, 0x8ULL}, 0xFFFFE000ULL, 0x0ULL},
  {32u, {0xFFFFFFE0ULL, 0xFFFFFFF6ULL, 0xFFFFFFB6ULL, 0xFFFFFFF9ULL, 0xFFFFFFF8ULL}, {0x0ULL, 0x9ULL, 0x49ULL, 0x6ULL, 0x7ULL}, 0xFFFFFFF0ULL, 0x8ULL},
  {64u, {0xFFFFFFFFFFFFFFC0ULL, 0xFFFFFFFFFFFFFFF6ULL, 0xFFFFFFFFFFFFFFB6ULL, 0xFFFFFFFFFFFFFFF9ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x9ULL, 0x49ULL, 0x6ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFC0ULL, 0xFFFFFFFFFFFFFFF6ULL, 0xFFFFFFFFFFFFFFB6ULL, 0xFFFFFFFFFFFFFFF9ULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x9ULL, 0x49ULL, 0x6ULL, 0x2ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x7ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFF00000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFF80ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x7ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFF000000000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[5], inO[5];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  inZ[3] = ssa_3[0].getZExtValue();
  inO[3] = ssa_3[1].getZExtValue();
  inZ[4] = ssa_4[0].getZExtValue();
  inO[4] = ssa_4[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 5; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
