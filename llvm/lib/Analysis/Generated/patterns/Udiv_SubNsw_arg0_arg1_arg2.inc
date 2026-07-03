namespace Udiv_SubNsw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xDDULL, 0xC0ULL, 0xFCULL}, {0x22ULL, 0x0ULL, 0x3ULL}, 0xA0ULL, 0x0ULL},
  {8u, {0xBDULL, 0x80ULL, 0xFCULL}, {0x42ULL, 0x0ULL, 0x3ULL}, 0xA0ULL, 0x0ULL},
  {8u, {0xC0ULL, 0xF8ULL, 0xF9ULL}, {0x0ULL, 0x0ULL, 0x6ULL}, 0xD0ULL, 0x0ULL},
  {8u, {0xC1ULL, 0xC0ULL, 0xE1ULL}, {0x3EULL, 0x0ULL, 0x1EULL}, 0xF4ULL, 0x0ULL},
  {16u, {0xFFFFULL, 0x0ULL, 0xFF02ULL}, {0x0ULL, 0xC000ULL, 0xFDULL}, 0xFF80ULL, 0x0ULL},
  {16u, {0x3FULL, 0x0ULL, 0xFF0CULL}, {0xFFC0ULL, 0xC000ULL, 0xF3ULL}, 0xFE80ULL, 0x0ULL},
  {16u, {0xFF00ULL, 0xFF80ULL, 0xFFFCULL}, {0x0ULL, 0x0ULL, 0x3ULL}, 0xAA80ULL, 0x0ULL},
  {32u, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFF02ULL}, {0x0ULL, 0xFFFC0000ULL, 0xFDULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0x2910ULL, 0x0ULL, 0xFFFFFF0CULL}, {0xFFFFD6EFULL, 0xFFFC0000ULL, 0xF3ULL}, 0xFEF24800ULL, 0x0ULL},
  {32u, {0xFFFFFE00ULL, 0xFFFFFFE0ULL, 0xFFFFFFF6ULL}, {0x0ULL, 0x0ULL, 0x9ULL}, 0xE38E38C0ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFFE0ULL, 0xFFFFFFF9ULL}, {0x1ULL, 0x0ULL, 0x6ULL}, 0xD5554000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFF3ULL}, {0x0ULL, 0x0ULL, 0xCULL}, 0xEAAAAAAAA0000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF80000001ULL}, {0x0ULL, 0x0ULL, 0x7FFFFFFEULL}, 0xFFFFFFFDFFFFFFF0ULL, 0x0ULL},
  {64u, {0x12BULL, 0x0ULL, 0xFFFFFFFFFFFFFE6FULL}, {0xFFFFFFFFFFFFFED4ULL, 0xFFFFFFFF80000000ULL, 0x190ULL}, 0xFF5C28F5C2800000ULL, 0x0ULL},
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
