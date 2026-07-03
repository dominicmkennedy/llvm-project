namespace Select_ICmpSlt_Mods_arg0_arg1_arg2_AddNsw_Mods_arg0_arg1_arg1_Mods_arg0_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0x0ULL, 0xFFE7ULL, 0xFFFFULL}, {0x0ULL, 0x18ULL, 0x0ULL}, 0xFFE0ULL, 0x0ULL},
  {16u, {0x0ULL, 0xFFC3ULL, 0xFFFFULL}, {0x0ULL, 0x3CULL, 0x0ULL}, 0xFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x7ULL, 0x0ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF9BULL, 0xFFFFFFFFULL}, {0x0ULL, 0x64ULL, 0x0ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF6ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x9ULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFBULL, 0xFFFFFFFFULL}, {0x0ULL, 0x4ULL, 0x0ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF2ULL, 0xFFFFFFFFULL}, {0x0ULL, 0xCULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFEAE7FULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x15180ULL, 0x0ULL}, 0xFFFFFFFFFFFE0000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFDC54EULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x23AB1ULL, 0x0ULL}, 0xFFFFFFFFFFFC0000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFF0BDBFULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0xF4240ULL, 0x0ULL}, 0xFFFFFFFFFFF00000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF8ULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x7ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x3ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFC46535FFULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x3B9ACA00ULL, 0x0ULL}, 0xFFFFFFFFC0000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFE6FULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x190ULL, 0x0ULL}, 0xFFFFFFFFFFFFFE00ULL, 0x0ULL},
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
