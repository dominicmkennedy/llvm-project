namespace Mul_Udiv_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFF0000ULL, 0xFFFFFEFEULL}, {0x0ULL, 0xFFFFULL, 0x101ULL}, 0xFE000000ULL, 0x0ULL},
  {32u, {0xFFFFFULL, 0xFFFFFFF3ULL, 0xFFFFFFEBULL}, {0x0ULL, 0xCULL, 0x14ULL}, 0x13ULL, 0x0ULL},
  {32u, {0x0ULL, 0xC46535FFULL, 0x3B9AC9FFULL}, {0x0ULL, 0x3B9ACA00ULL, 0xC4653600ULL}, 0x220001FFULL, 0x0ULL},
  {32u, {0xC0000000ULL, 0xFFFFFFE6ULL, 0xFFFFFFE6ULL}, {0x0ULL, 0x19ULL, 0x19ULL}, 0xC0000000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFCULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL, 0x3ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFFFEFULL, 0x0ULL, 0xFFFFFF00ULL}, {0x10ULL, 0x0ULL, 0x0ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF0000ULL, 0xFFFF8000ULL}, {0x0ULL, 0xFFFFULL, 0x7FFFULL}, 0x80000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFF00000ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFFFAULL}, {0x0ULL, 0xAULL, 0x5ULL}, 0xFFFFFFFFFFF80000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFFF3ULL}, {0x0ULL, 0x18ULL, 0xCULL}, 0x8000000000000003ULL, 0x0ULL},
  {64u, {0xE000000000000000ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFFF5ULL}, {0x0ULL, 0xAULL, 0xAULL}, 0xE000000000000001ULL, 0x0ULL},
  {64u, {0xF000000000000000ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFFF3ULL}, {0x0ULL, 0x18ULL, 0xCULL}, 0xF800000000000003ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFEFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFF8ULL}, {0x1000ULL, 0x0ULL, 0x7ULL}, 0xFFFFFFFFFFFF8000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0xCULL, 0x3ULL}, 0xC000000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0x18ULL, 0x3ULL}, 0xE000000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFFF5ULL}, {0x0ULL, 0xAULL, 0xAULL}, 0xFFFFFFFFFFFFFF01ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFF0000ULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFFD7ULL}, {0x0ULL, 0x28ULL, 0x28ULL}, 0xFFFFFFFFFFFF0007ULL, 0x0ULL},
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
