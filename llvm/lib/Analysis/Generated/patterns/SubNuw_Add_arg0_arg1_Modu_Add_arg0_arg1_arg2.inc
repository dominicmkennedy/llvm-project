namespace SubNuw_Add_arg0_arg1_Modu_Add_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFC17ULL}, {0x0ULL, 0x0ULL, 0x3E8ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x17ULL, 0xFFFFFFFFFFFFFFE7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFE8ULL, 0x18ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x47ULL, 0xFFFFFFFFFFFFFFB7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFB8ULL, 0x48ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x27ULL, 0xFFFFFFFFFFFFFFD7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFD8ULL, 0x28ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0x37ULL, 0xFFFFFFFFFFFFFFC7ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFC8ULL, 0x38ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF7ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x8ULL, 0x8ULL}, 0x7ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFE2ULL, 0xFFFFFFFFFFFFFFE1ULL}, {0x0ULL, 0x1DULL, 0x1EULL}, 0x1ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFDULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x2ULL, 0x2ULL}, 0x1ULL, 0x0ULL},
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
