namespace ShlNsw_arg0_SubNsw_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFF0ULL, 0xFFFFFE00ULL}, {0xFFFFFFFFULL, 0xFULL, 0x0ULL}, 0x0ULL, 0xFFFF8000ULL},
  {32u, {0x0ULL, 0xFFFFFFF9ULL, 0x80000000ULL}, {0xFFFFFFFFULL, 0x6ULL, 0x0ULL}, 0x0ULL, 0xFFFFFFC0ULL},
  {32u, {0x0ULL, 0xFFFFFFDFULL, 0xFFFFFFE0ULL}, {0xFFFFFFFFULL, 0x20ULL, 0x0ULL}, 0x1ULL, 0x80000000ULL},
  {32u, {0x0ULL, 0xFFFFFFE1ULL, 0xFFFFFFE0ULL}, {0xFFFFFFFFULL, 0x1EULL, 0x0ULL}, 0x0ULL, 0xC0000000ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0x80000000ULL}, {0xFFFFFFFFULL, 0x7ULL, 0x0ULL}, 0x0ULL, 0xFFFFFF80ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0x0ULL}, {0x0ULL, 0x0ULL, 0x80000000ULL}, 0x1ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFF00ULL}, {0xFFFFFFFFULL, 0x8ULL, 0x0ULL}, 0x0ULL, 0xFFFFFF00ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL, 0xFFFFFFE0ULL}, {0xFFFFFFFFULL, 0x18ULL, 0x0ULL}, 0x0ULL, 0xFF000000ULL},
  {32u, {0x0ULL, 0xFFFFFFE5ULL, 0xFFFFFFE0ULL}, {0xFFFFFFFFULL, 0x1AULL, 0x0ULL}, 0x0ULL, 0xFC000000ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC3ULL, 0xFFFFFFFFFFFFFFC0ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x3CULL, 0x0ULL}, 0x0ULL, 0xF000000000000000ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC1ULL, 0xFFFFFFFF80000000ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x3EULL, 0x20ULL}, 0x0ULL, 0xFFFFFFFFC0000000ULL},
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
