namespace Select_ICmpSlt_arg0_arg1_AddNsw_arg1_arg2_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xF3ULL, 0xE0ULL, 0xBULL}, {0xCULL, 0x0ULL, 0xF4ULL}, 0xE0ULL, 0x0ULL},
  {32u, {0xFFFFFFFDULL, 0xFFFFFF00ULL, 0x1ULL}, {0x2ULL, 0x0ULL, 0xFFFFFFFEULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFBFE5ULL, 0x80000000ULL, 0x401AULL}, {0x401AULL, 0x0ULL, 0xFFFFBFE5ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFEAE80ULL, 0x80000000ULL, 0x1517FULL}, {0x1517FULL, 0x0ULL, 0xFFFEAE80ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFE0000ULL, 0xFFFEULL}, {0xFFFFULL, 0x0ULL, 0xFFFF0001ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0xFFFFFFDFULL, 0xFFFFFF00ULL, 0x1CULL}, {0x20ULL, 0x0ULL, 0xFFFFFFE3ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0xFFFFFFF8ULL, 0x2ULL}, {0x3ULL, 0x0ULL, 0xFFFFFFFDULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {64u, {0xE000000000000001ULL, 0xC000000000000000ULL, 0x1FFFFFFFFFFFFFFEULL}, {0x1FFFFFFFFFFFFFFEULL, 0x0ULL, 0xE000000000000001ULL}, 0xC000000000000000ULL, 0x0ULL},
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
