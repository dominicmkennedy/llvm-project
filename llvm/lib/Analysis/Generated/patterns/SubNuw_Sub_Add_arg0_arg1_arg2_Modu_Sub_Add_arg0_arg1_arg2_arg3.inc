namespace SubNuw_Sub_Add_arg0_arg1_arg2_Modu_Sub_Add_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0x0ULL, 0x17ULL, 0x0ULL, 0xFFFFFFFFFFFFFFE7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFE8ULL, 0x0ULL, 0x18ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x5ULL, 0x0ULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFAULL, 0x0ULL, 0x6ULL}, 0x1ULL, 0x0ULL},
  {64u, {0x0ULL, 0x6FULL, 0x0ULL, 0xFFFFFFFFFFFFFFC7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFF90ULL, 0x0ULL, 0x38ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x87ULL, 0x0ULL, 0xFFFFFFFFFFFFFF77ULL}, {0x0ULL, 0xFFFFFFFFFFFFFF78ULL, 0x0ULL, 0x88ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x47ULL, 0x0ULL, 0xFFFFFFFFFFFFFFB7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFB8ULL, 0x0ULL, 0x48ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x27ULL, 0x0ULL, 0xFFFFFFFFFFFFFFD7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFD8ULL, 0x0ULL, 0x28ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x57ULL, 0x0ULL, 0xFFFFFFFFFFFFFFA7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFA8ULL, 0x0ULL, 0x58ULL}, 0x7ULL, 0x0ULL},
  {64u, {0xFULL, 0xFFFFFFFFFFFFFE7FULL, 0x0ULL, 0xFFFFFFFFFFFFFFE7ULL}, {0x0ULL, 0x180ULL, 0x0ULL, 0x18ULL}, 0x7ULL, 0x0ULL},
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
