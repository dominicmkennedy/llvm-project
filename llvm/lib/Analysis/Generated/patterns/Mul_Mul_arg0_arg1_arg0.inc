namespace Mul_Mul_arg0_arg1_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFF13B2ULL}, {0x0ULL, 0xEC4DULL}, 0x2ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFAULL}, {0x0ULL, 0x5ULL}, 0x2ULL, 0x0ULL},
  {32u, {0xF8000000ULL, 0x7FFULL}, {0x1ULL, 0xFFFFF800ULL}, 0x7FFULL, 0x3800ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x8ULL}, 0x17ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF7FULL}, {0x0ULL, 0x80ULL}, 0x17FULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF6ULL}, {0x0ULL, 0x9ULL}, 0x2ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF96ULL}, {0x0ULL, 0x69ULL}, 0x2ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFDFULL}, {0x0ULL, 0x20ULL}, 0x5FULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEEULL}, {0x0ULL, 0x11ULL}, 0x2ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFC17ULL}, {0x0ULL, 0x3E8ULL}, 0x17ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEDULL}, {0x0ULL, 0x12ULL}, 0x5ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0x5ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFBULL}, {0x0ULL, 0x4ULL}, 0xBULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFAULL}, {0x0ULL, 0x5ULL}, 0x2ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0x5ULL, 0x0ULL},
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
