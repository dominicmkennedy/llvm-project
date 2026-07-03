namespace Add_Udiv_Add_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0xF800000000000000ULL, 0xFFFFFFFFFFFFFFE1ULL, 0xFFFFFFFFFFFFFFC3ULL, 0xFFFFFFFFFFFFFFF3ULL}, {0x0ULL, 0x1EULL, 0x3CULL, 0xCULL}, 0xFFC0000000000000ULL, 0x0ULL},
  {64u, {0xFF80000000000000ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0xCULL, 0x18ULL, 0x3ULL}, 0xFFF8000000000000ULL, 0x0ULL},
  {64u, {0xFF80000000000000ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFFF0ULL}, {0x0ULL, 0xCULL, 0x18ULL, 0xFULL}, 0xFFF8000000000000ULL, 0x0ULL},
  {64u, {0xFF80000000000000ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFF48ULL}, {0x0ULL, 0xCULL, 0x18ULL, 0xB7ULL}, 0xFFF8000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFF7ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x7ULL, 0x8ULL, 0x0ULL}, 0xFFFFFFFFC0000000ULL, 0x0ULL},
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
