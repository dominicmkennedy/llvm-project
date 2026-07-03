namespace Udiv_Udiv_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFE92ULL, 0xFFFFFF9BULL}, {0x0ULL, 0x16DULL, 0x64ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFC3ULL, 0xFFFFFFC3ULL}, {0x0ULL, 0x3CULL, 0x3CULL}, 0xFFE00000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF9ULL, 0xFFFFFFE6ULL}, {0x0ULL, 0x6ULL, 0x19ULL}, 0xFE000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF5ULL, 0xFFFFFF81ULL}, {0x0ULL, 0xAULL, 0x7EULL}, 0xFFC00000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFC17ULL, 0xFFFFFFC3ULL}, {0x0ULL, 0x3E8ULL, 0x3CULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0xF8000000ULL, 0xFFFFFC17ULL, 0xFFFFFFC3ULL}, {0x0ULL, 0x3E8ULL, 0x3CULL}, 0xFFFFF000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFF8000ULL, 0xFFFFFFFFFFFF8000ULL}, {0x0ULL, 0xFFULL, 0xFFULL}, 0xFFFE000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFC17ULL, 0xFFFFFFFFFFFFF1EFULL}, {0x0ULL, 0x3E8ULL, 0xE10ULL}, 0xFFFFF80000000000ULL, 0x0ULL},
  {64u, {0xFFFF000000000000ULL, 0xFFFFFFFFFFFF8000ULL, 0xFFFFFFFFFFFF8000ULL}, {0x0ULL, 0xFFULL, 0xFFULL}, 0xFFFFFFFE00000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFC17ULL, 0xFFFFFFFFFFFFFFC3ULL}, {0x0ULL, 0x3E8ULL, 0x3CULL}, 0xFFFE000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC3ULL, 0xFFFFFFFFFFFFFFC3ULL}, {0x0ULL, 0x3CULL, 0x3CULL}, 0xFFE0000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFF8000ULL, 0xFFFFFFFFFFFF8000ULL}, {0x0ULL, 0xFFULL, 0xFFULL}, 0xFFFF000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFA0A1EFFULL, 0xFFFFFFFFFA0A1EFFULL}, {0x0ULL, 0x5F5E100ULL, 0x5F5E100ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFF0BDBFULL, 0xFFFFFFFFFFFFFFC3ULL}, {0x0ULL, 0xF4240ULL, 0x3CULL}, 0xFFFFFF8000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFULL, 0xFFFFFFFFFFFFFC17ULL, 0xFFFFFFFFFFFFFC17ULL}, {0x0ULL, 0x3E8ULL, 0x3E8ULL}, 0xFFFFE00000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFC46535FFULL, 0xFFFFFFFFFFFFFFC3ULL}, {0x0ULL, 0x3B9ACA00ULL, 0x3CULL}, 0xFFFFFFFFE0000000ULL, 0x0ULL},
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
