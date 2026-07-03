namespace Select_ICmpEq_And_arg0_arg1_arg2_arg2_SubNswNuw_arg3_And_arg0_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0x80ULL, 0xE0ULL, 0xFFULL, 0xDFULL}, {0x0ULL, 0x1FULL, 0x0ULL, 0x20ULL}, 0xE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFFULL, 0xFFFFFFFBULL}, {0x0ULL, 0x3ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFFFULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x7ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFC0ULL, 0xFFFFFFFFULL, 0xFFFFFFBFULL}, {0x0ULL, 0x3FULL, 0x0ULL, 0x40ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE0ULL, 0xFFFFFFFFULL, 0xFFFFFFDFULL}, {0x0ULL, 0x1FULL, 0x0ULL, 0x20ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFF800ULL, 0xFFFFFFFFULL, 0xFFFFF7FFULL}, {0x0ULL, 0x7FFULL, 0x0ULL, 0x800ULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFC00ULL, 0xFFFFFFFFULL, 0xFFFFFBFFULL}, {0x0ULL, 0x3FFULL, 0x0ULL, 0x400ULL}, 0xFFFFFC00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFE00ULL, 0xFFFFFFFFULL, 0xFFFFFDFFULL}, {0x0ULL, 0x1FFULL, 0x0ULL, 0x200ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF0000ULL, 0xFFFFFFFFULL, 0xFFFEFFFFULL}, {0x0ULL, 0xFFFFULL, 0x0ULL, 0x10000ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF0ULL, 0xFFFFFFFFULL, 0xFFFFFFEFULL}, {0x0ULL, 0xFULL, 0x0ULL, 0x10ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x7ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x3ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFEFULL}, {0x0ULL, 0xFULL, 0x0ULL, 0x10ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFE0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x1FULL, 0x0ULL, 0x20ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
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
