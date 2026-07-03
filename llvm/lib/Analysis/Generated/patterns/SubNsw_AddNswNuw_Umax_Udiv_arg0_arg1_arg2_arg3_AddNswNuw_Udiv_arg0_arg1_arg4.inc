namespace SubNsw_AddNswNuw_Umax_Udiv_arg0_arg1_arg2_arg3_AddNswNuw_Udiv_arg0_arg1_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFEAULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x15ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0xCULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFD5ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x2AULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF6ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x9ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF9ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x6ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0xAULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x5ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFAAULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x55ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x7ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0xC000000000000000ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x3ULL, 0x5ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
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
