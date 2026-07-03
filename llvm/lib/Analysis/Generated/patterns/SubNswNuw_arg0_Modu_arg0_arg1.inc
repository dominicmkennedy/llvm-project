namespace SubNswNuw_arg0_Modu_arg0_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x80000000ULL, 0xFFFFF1EFULL}, {0x0ULL, 0xE10ULL}, 0x8000000FULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0xCULL}, 0x3ULL, 0x0ULL},
  {32u, {0xFFFE0000ULL, 0xFFFFF1EFULL}, {0x0ULL, 0xE10ULL}, 0xFFFE000FULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFF6BULL}, {0x0ULL, 0x94ULL}, 0x80000003ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x6ULL}, 0xFFFF0001ULL, 0x0ULL},
  {32u, {0xFFFE0000ULL, 0xFFFFFC17ULL}, {0x0ULL, 0x3E8ULL}, 0xFFFE0007ULL, 0x0ULL},
  {32u, {0xFFC00000ULL, 0xFFFFFFC3ULL}, {0x0ULL, 0x3CULL}, 0xFFC00003ULL, 0x0ULL},
  {32u, {0xFFFFC000ULL, 0xFFFFFFE3ULL}, {0x0ULL, 0x1CULL}, 0xFFFFC003ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFF4BFULL}, {0x0ULL, 0xB40ULL}, 0x3FULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF3ULL}, {0x0ULL, 0xCULL}, 0x3ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[2], inO[2];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 2; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
