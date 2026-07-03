namespace OrDisjoint_And_ShlNswNuw_arg0_arg1_arg2_Lshr_arg0_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x80000000ULL, 0xFFFFFFFEULL, 0xFFFFFFF1ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x1ULL, 0xEULL, 0x3ULL}, 0xF8000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFC0FFULL, 0xFFFFFFF3ULL}, {0x0ULL, 0x2ULL, 0x3F00ULL, 0xCULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFC0FFULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x8ULL, 0x3F00ULL, 0x6ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFC7ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL, 0x38ULL, 0x3ULL}, 0xFE000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFEULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL, 0x2ULL, 0x1ULL}, 0xE0000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF0FULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x1ULL, 0xF0ULL, 0x4ULL}, 0xFC00000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF0FULL, 0xFFFFFFFFFFFFFFFAULL}, {0x0ULL, 0x1ULL, 0xF0ULL, 0x5ULL}, 0xFE00000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFF0FULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x0ULL, 0x1ULL, 0xF0ULL, 0x6ULL}, 0xFF00000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFE0001FULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x5ULL, 0x1FFFE0ULL, 0x20ULL}, 0xFFFFFFFFFC000000ULL, 0x0ULL},
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
