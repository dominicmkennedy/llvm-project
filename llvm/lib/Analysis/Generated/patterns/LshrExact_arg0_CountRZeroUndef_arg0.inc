namespace LshrExact_arg0_CountRZeroUndef_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[1], argO[1], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL}, {0x0ULL}, 0x0ULL, 0x1ULL},
  {32u, {0xFFFF8000ULL}, {0x0ULL}, 0xFFFF8000ULL, 0x1ULL},
  {32u, {0x80000000ULL}, {0x0ULL}, 0x80000000ULL, 0x1ULL},
  {64u, {0x0ULL}, {0x0ULL}, 0x0ULL, 0x1ULL},
  {64u, {0xFFFFFFFF00000000ULL}, {0x0ULL}, 0xFFFFFFFF00000000ULL, 0x1ULL},
  {64u, {0x8000000000000000ULL}, {0x0ULL}, 0x8000000000000000ULL, 0x1ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL}, {0x0ULL}, 0xFFFFFFFFFFFFFF00ULL, 0x1ULL},
  {64u, {0xFFFFFFFFFFFF0000ULL}, {0x0ULL}, 0xFFFFFFFFFFFF0000ULL, 0x1ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[1], inO[1];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 1; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
