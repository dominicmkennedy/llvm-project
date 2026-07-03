namespace Lshr_arg0_ZextBool_ICmpUlt_arg1_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFDE7ULL}, {0x0ULL, 0x218ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF37ULL}, {0x0ULL, 0xC8ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFBULL}, {0x0ULL, 0x4ULL}, 0x80000000ULL, 0x0ULL},
  {64u, {0xFFFE000000000000ULL, 0xFFFF000000000000ULL}, {0x0ULL, 0xFFFFFFFFFFFFULL}, 0xFFFF000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFF000000000000ULL}, {0x0ULL, 0xFFFFFFFFFFFFULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0xFFF8000000000000ULL, 0xFFFF000000000000ULL}, {0x0ULL, 0xFFFFFFFFFFFFULL}, 0xFFFC000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFDFFFULL}, {0x0ULL, 0x2000ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFEFFFULL}, {0x0ULL, 0x1000ULL}, 0x8000000000000000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[2], inO[2];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 2; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
