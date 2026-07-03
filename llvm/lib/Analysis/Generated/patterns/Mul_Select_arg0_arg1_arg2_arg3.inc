namespace Mul_Select_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL, 0xFFFF0000ULL}, {0x0ULL, 0x2ULL, 0x1ULL, 0x0ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL, 0xFFFC0000ULL}, {0x0ULL, 0x2ULL, 0x1ULL, 0x0ULL}, 0xFFF80000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFEFFULL, 0xFFFFFF80ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x100ULL, 0x0ULL, 0x1ULL}, 0xFFFFFC00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEDULL, 0xFFFFFFF0ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x12ULL, 0xFULL, 0x3ULL}, 0xFFFFFFC0ULL, 0x24ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFCFULL, 0xFFFFFFFFFFFFFFBFULL, 0xFFFFFFFF00000000ULL}, {0x0ULL, 0x30ULL, 0x40ULL, 0x0ULL}, 0xFFFFFFC00000000FULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF7ULL, 0xFFFFFFFFFFFFFFEFULL, 0xFFFFFFFF00000000ULL}, {0x0ULL, 0x8ULL, 0x10ULL, 0x0ULL}, 0xFFFFFFF000000007ULL, 0x0ULL},
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
