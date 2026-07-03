namespace AddNswNuw_Mul_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFF0000ULL, 0xFFFFFF00ULL, 0xFFFF7F7FULL}, {0x0ULL, 0x0ULL, 0x8080ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFF00ULL, 0xFFFFFEFEULL}, {0x0ULL, 0x0ULL, 0x101ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFF3ULL, 0xFFFFFFE5ULL}, {0x0ULL, 0xCULL, 0x1AULL}, 0xFFFFF001ULL, 0x2ULL},
  {32u, {0xFFFF0001ULL, 0xFFFFFF00ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0x3ULL}, 0xFF000000ULL, 0x1ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFF5ULL, 0xFFFFFFF0ULL}, {0x0ULL, 0xAULL, 0x0ULL}, 0xFFFFF000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFED7ULL, 0xFFFFFFFFFFFFFF8FULL}, {0x0ULL, 0x128ULL, 0x70ULL}, 0xFFFFFE0000000007ULL, 0x0ULL},
  {64u, {0xFFFFFFE000000000ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFF8ULL}, {0x0ULL, 0x0ULL, 0x7ULL}, 0xFFFFFF0000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFF80ULL}, {0x0ULL, 0xAULL, 0x0ULL}, 0xFFFFFFF800000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x18ULL, 0x8ULL}, 0xFFFFFFFFFFFFFF07ULL, 0x0ULL},
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
