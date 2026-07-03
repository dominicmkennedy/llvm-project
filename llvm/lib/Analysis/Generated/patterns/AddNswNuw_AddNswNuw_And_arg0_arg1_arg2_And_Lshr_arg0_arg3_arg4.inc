namespace AddNswNuw_AddNswNuw_And_arg0_arg1_arg2_And_Lshr_arg0_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0x0ULL, 0xFEULL, 0xFCULL, 0xFEULL, 0xFCULL}, {0x0ULL, 0x1ULL, 0x0ULL, 0x1ULL, 0x3ULL}, 0xF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFF800000ULL, 0xFFFFF000ULL, 0xFFFFFFF2ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x7FFFFFULL, 0xFFFULL, 0xDULL, 0x1ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFEULL, 0xF8000000ULL, 0xFFFFFFFCULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL, 0x0ULL, 0x3ULL, 0x1ULL}, 0xF0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xE0000000ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL, 0x0ULL, 0x2ULL, 0x1ULL}, 0xC0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xFE000000ULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL, 0x0ULL, 0x1ULL, 0x1ULL}, 0xFC000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFF0000000000ULL, 0xFFFFFFFFFFFFFFF7ULL, 0xFFFFFFFFFFFFFF00ULL}, {0x0ULL, 0xFFULL, 0x0ULL, 0x8ULL, 0xFFULL}, 0xFFFFFE0000000000ULL, 0x0ULL},
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
