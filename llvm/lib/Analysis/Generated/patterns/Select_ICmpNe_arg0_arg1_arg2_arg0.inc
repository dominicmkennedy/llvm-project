namespace Select_ICmpNe_arg0_arg1_arg2_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x1ULL}, 0xFFFFFFFEULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFFDULL}, {0x0ULL, 0x0ULL, 0x2ULL}, 0xFFFFFFFDULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x2ULL, 0x1ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0xFFFFFFFCULL, 0xFFFFFFFDULL}, {0x0ULL, 0x3ULL, 0x2ULL}, 0xFFFFFFFCULL, 0x2ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0x15FULL}, {0x0ULL, 0x0ULL, 0xFFFFFEA0ULL}, 0x15FULL, 0x0ULL},
  {32u, {0xC46535FFULL, 0xFFFFFFFFULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0x7FFFFFFFULL}, {0x0ULL, 0x0ULL, 0x80000000ULL}, 0x7FFFFFFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xAAULL}, {0x0ULL, 0x0ULL, 0xFFFFFF55ULL}, 0xAAULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0x8BULL}, {0x0ULL, 0x0ULL, 0xFFFFFF74ULL}, 0x8BULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFF4ULL}, {0x0ULL, 0x0ULL, 0xBULL}, 0xFFFFFFF4ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFA0ULL}, {0x0ULL, 0x0ULL, 0x5FULL}, 0xFFFFFFA0ULL, 0x0ULL},
  {32u, {0x0ULL, 0x1ULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFFFFFFEULL, 0x0ULL}, 0x1ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0x6FULL}, {0x0ULL, 0x0ULL, 0xFFFFFF90ULL}, 0x6FULL, 0x0ULL},
  {32u, {0x0ULL, 0x6BULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFFFFF94ULL, 0x0ULL}, 0x6BULL, 0x0ULL},
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
