namespace Add_Add_Select_arg0_arg1_arg2_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0xFFFFFFE7ULL, 0xFFFFFF00ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x8ULL, 0x0ULL, 0x1ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFEFFFFULL, 0xFFFFFBFFULL, 0xFFFF0000ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x10000ULL, 0x400ULL, 0x0ULL, 0x1ULL}, 0xFFFC0000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFF7FFFFULL, 0xFFFFFFFFFFFEFFFFULL, 0x0ULL, 0xFFFFFFFFFE000000ULL}, {0x0ULL, 0x80000ULL, 0x10000ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL}, 0xFFFFFFFFFC000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFDULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x2ULL, 0x3ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFF7FFFFULL, 0xFFFFFFFFFFFEFFFFULL, 0x0ULL, 0xFFFFFFFFFC000000ULL}, {0x0ULL, 0x80000ULL, 0x10000ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL}, 0xFFFFFFFFF8000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFDULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x3ULL, 0x2ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF4ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFE00ULL, 0xFFFFFFFFFFFFFF37ULL}, {0x0ULL, 0xBULL, 0x0ULL, 0x0ULL, 0xC8ULL}, 0xFFFFFFFFFFFFFC00ULL, 0x0ULL},
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
