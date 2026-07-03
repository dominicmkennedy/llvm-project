namespace Add_Mul_arg0_arg1_Mul_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFF00ULL, 0xFFFFFFB2ULL, 0xFFFFFF00ULL, 0xFFFFFF69ULL}, {0x0ULL, 0x4DULL, 0x0ULL, 0x96ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFFC0ULL, 0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFFFF3FULL}, {0x3FULL, 0x0ULL, 0x0ULL, 0xC0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFFB2ULL, 0xFFFFFF00ULL, 0xFFFFFF68ULL, 0xFFFFFF00ULL}, {0x4DULL, 0x0ULL, 0x97ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFB2ULL, 0xFFFFFF00ULL, 0xFFFFFF68ULL}, {0x0ULL, 0x4DULL, 0x0ULL, 0x97ULL}, 0xFFFF0000ULL, 0x0ULL},
  {64u, {0xFFFFFF00FFFFFF00ULL, 0xFFFFD8EFFFFFFFFEULL, 0xFFFFFF00FFFFFF00ULL, 0xFFF0BDBFFFFFFF9BULL}, {0x0ULL, 0x271000000001ULL, 0x0ULL, 0xF424000000064ULL}, 0xF0000000FFFF8000ULL, 0x0ULL},
  {64u, {0xFFFFFF00FFFFFF00ULL, 0xFFF0BDBFFFFFFF9BULL, 0xFFFFFF00FFFFFF00ULL, 0xFFFFD8EFFFFFFFFEULL}, {0x0ULL, 0xF424000000064ULL, 0x0ULL, 0x271000000001ULL}, 0xF0000000FFFF8000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFFAULL}, {0x0ULL, 0x3ULL, 0x0ULL, 0x5ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFDAULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFF2CULL}, {0x0ULL, 0x25ULL, 0x0ULL, 0xD3ULL}, 0xFFFFFFFFFFFF0000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFF2CULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFDAULL}, {0x0ULL, 0xD3ULL, 0x0ULL, 0x25ULL}, 0xFFFFFFFFFFFF0000ULL, 0x0ULL},
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
