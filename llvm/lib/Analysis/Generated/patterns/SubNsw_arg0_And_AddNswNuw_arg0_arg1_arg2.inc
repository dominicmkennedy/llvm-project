namespace SubNsw_arg0_And_AddNswNuw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFF80ULL, 0xFFFFFFBAULL, 0xFFFFFF01ULL}, {0x0ULL, 0x45ULL, 0xFEULL}, 0x40ULL, 0xFFFFFFB8ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFFBAULL, 0xFFFFFF01ULL}, {0x0ULL, 0x45ULL, 0xFEULL}, 0x40ULL, 0xB8ULL},
  {32u, {0xFFFFFE00ULL, 0xFFFFFF76ULL, 0xFFFFFC03ULL}, {0x0ULL, 0x89ULL, 0x3FCULL}, 0x80ULL, 0xFFFFFF70ULL},
  {64u, {0xFF80000000000007ULL, 0xFFFFFFFFFFFFFB7FULL, 0xFFFFFFFFFFFFF007ULL}, {0x0ULL, 0x480ULL, 0xFF8ULL}, 0x47FULL, 0xB80ULL},
  {64u, {0xFF80000000000007ULL, 0xFFFFFFFFFFFFE387ULL, 0xFFFFFFFFFFFFF007ULL}, {0x0ULL, 0x1C78ULL, 0xFF8ULL}, 0xC77ULL, 0x388ULL},
  {64u, {0xFFFFFFFC00000003ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFE003ULL}, {0x0ULL, 0xCULL, 0x1FFCULL}, 0xBULL, 0x1FF4ULL},
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
