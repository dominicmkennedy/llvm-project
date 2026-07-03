namespace ShlNswNuw_arg0_SubNsw_arg1_Mods_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF8ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x7ULL, 0x0ULL, 0x8ULL}, 0xFFFF8000ULL, 0x0ULL},
  {32u, {0xFFFFFFF0ULL, 0xFFFFFFF3ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0xFULL, 0xCULL, 0x0ULL, 0x8ULL}, 0xFF80001FULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0xFFFFFFF1ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x3ULL, 0xEULL, 0x0ULL, 0x8ULL}, 0xFF80007FULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF8ULL, 0x3ULL, 0xFFFFFFF7ULL}, {0x1ULL, 0x7ULL, 0x0ULL, 0x8ULL}, 0xFFFFF777ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF3ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x1ULL, 0xCULL, 0x0ULL, 0x8ULL}, 0xFFF0001FULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFF7ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x8ULL, 0x0ULL, 0x8ULL}, 0xFF800001ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF8ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x1ULL, 0x7ULL, 0x3ULL, 0x8ULL}, 0xFFFFEEEEULL, 0x0ULL},
  {32u, {0xFFFFFFF8ULL, 0xFFFFFFF2ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x7ULL, 0xDULL, 0x0ULL, 0x8ULL}, 0xFF80003FULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF8ULL, 0x2ULL, 0xFFFFFFF7ULL}, {0x1ULL, 0x7ULL, 0x1ULL, 0x8ULL}, 0xFFFFBBBBULL, 0x0ULL},
  {32u, {0xFFFFFFF9ULL, 0xFFFFFFF2ULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x6ULL, 0xDULL, 0x0ULL, 0x8ULL}, 0xFF80007FULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFF8ULL, 0x1ULL, 0xFFFFFFF7ULL}, {0x1ULL, 0x7ULL, 0x2ULL, 0x8ULL}, 0xFFFFDDDDULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFFAULL, 0x0ULL, 0xFFFFFFF9ULL}, {0x1ULL, 0x5ULL, 0x0ULL, 0x6ULL}, 0xFFFFF800ULL, 0x0ULL},
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
