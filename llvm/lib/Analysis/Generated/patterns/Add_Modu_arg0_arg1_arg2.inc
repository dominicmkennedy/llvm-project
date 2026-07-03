namespace Add_Modu_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFC17ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x3E8ULL, 0x1ULL}, 0xFFFFFC00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF6ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x9ULL, 0x1ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF9BULL, 0xFFFFFFFEULL}, {0x0ULL, 0x64ULL, 0x1ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFCEULL, 0xFFFFFFFDULL}, {0x0ULL, 0x31ULL, 0x2ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x18ULL, 0x1ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFEULL}, {0x0ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF9ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x6ULL, 0x1ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF1ULL, 0xFFFFFFFEULL}, {0x0ULL, 0xEULL, 0x1ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC8ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x37ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFD8FULL, 0xFFFFFFFFFFFFFECDULL}, {0x0ULL, 0x270ULL, 0x132ULL}, 0xFFFFFFFFFFFFFC00ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x3ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFECULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x13ULL, 0x1ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
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
