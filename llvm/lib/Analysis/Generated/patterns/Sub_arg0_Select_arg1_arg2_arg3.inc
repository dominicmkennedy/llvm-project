namespace Sub_arg0_Select_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xFFULL, 0x0ULL, 0xF7ULL, 0xFEULL}, {0x0ULL, 0x0ULL, 0x8ULL, 0x1ULL}, 0x0ULL, 0xF8ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0x5FULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0xFFFFFFA0ULL, 0x0ULL}, 0xFFFFFF9FULL, 0x0ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0x1ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0xFFFFFFFEULL, 0x0ULL}, 0xFFFFFFFDULL, 0x0ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFULL, 0x0ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0xFFFFFFC0ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFEBULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x14ULL, 0x0ULL}, 0x13ULL, 0x0ULL},
  {32u, {0xFFFFFFBFULL, 0x0ULL, 0xFFFFFFBFULL, 0xFFFFFFDFULL}, {0x40ULL, 0x0ULL, 0x40ULL, 0x20ULL}, 0xFFFFFFDFULL, 0x0ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFBULL, 0xFFFFFFF6ULL}, {0x0ULL, 0x0ULL, 0x4ULL, 0x9ULL}, 0x0ULL, 0xFFFFFFF4ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0x0ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x3ULL, 0x0ULL}, 0x2ULL, 0x0ULL},
  {32u, {0x7ULL, 0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x1ULL}, 0x0ULL, 0x6ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFF7FFFFULL, 0xFFFFFFFFFFFEFFFFULL}, {0x0ULL, 0x0ULL, 0x80000ULL, 0x10000ULL}, 0xFFFFULL, 0xFFFFFFFFFFF80000ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFAD9A3FFULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x5265C00ULL, 0x0ULL}, 0x5265BFFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFEBE2289FFFULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x141DD76000ULL, 0x0ULL}, 0x141DD75FFFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFB16B6EB0FFFFULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x4E94914F0000ULL, 0x0ULL}, 0x4E94914EFFFFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFFFFE7ULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x18ULL}, 0x17ULL, 0xFFFFFFFFFFFFFFE0ULL},
  {64u, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFC844B6ULL, 0xFFFFFFFFFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x37BB49ULL, 0x0ULL}, 0x37BB48ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFF9ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x6ULL, 0x0ULL, 0x0ULL, 0x6ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
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
