namespace Select_ICmpUlt_arg0_arg1_ShlNuw_arg0_arg2_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0x0ULL, 0xFEFFULL, 0xFFF7ULL}, {0x0ULL, 0x100ULL, 0x8ULL}, 0xFFULL, 0x0ULL},
  {16u, {0x0ULL, 0xEFFFULL, 0xFFFBULL}, {0x0ULL, 0x1000ULL, 0x4ULL}, 0xFULL, 0x0ULL},
  {16u, {0x7ULL, 0xEFFFULL, 0xFFFBULL}, {0x0ULL, 0x1000ULL, 0x4ULL}, 0x7FULL, 0x0ULL},
  {16u, {0x7ULL, 0xFEFFULL, 0xFFF7ULL}, {0x0ULL, 0x100ULL, 0x8ULL}, 0x7FFULL, 0x0ULL},
  {16u, {0x0ULL, 0xBFFFULL, 0xFFFDULL}, {0x0ULL, 0x4000ULL, 0x2ULL}, 0x3ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFEFFFFULL, 0xFFFFFFEFULL}, {0x0ULL, 0x10000ULL, 0x10ULL}, 0xFFFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFEFFFFFFULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x1000000ULL, 0x8ULL}, 0xFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xEFFFFFFFULL, 0xFFFFFFFBULL}, {0x0ULL, 0x10000000ULL, 0x4ULL}, 0xFULL, 0x0ULL},
  {32u, {0x0ULL, 0xBFFFFFFFULL, 0xFFFFFFFDULL}, {0x0ULL, 0x40000000ULL, 0x2ULL}, 0x3ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFEFFFFFFFFULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x100000000ULL, 0x20ULL}, 0xFFFFFFFFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFEFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFEFULL}, {0x0ULL, 0x1000000000000ULL, 0x10ULL}, 0xFFFFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFEFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x100000000000000ULL, 0x8ULL}, 0xFFULL, 0x0ULL},
  {64u, {0x0ULL, 0xEFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x1000000000000000ULL, 0x4ULL}, 0xFULL, 0x0ULL},
  {64u, {0x0ULL, 0xBFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x4000000000000000ULL, 0x2ULL}, 0x3ULL, 0x0ULL},
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
