namespace AddNsw_SubNswNuw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFDFULL, 0xFFFFFFE0ULL, 0x0ULL}, {0x20ULL, 0x0ULL, 0xFFFFFFFFULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFF1FFULL, 0xFFFFFFF8ULL, 0x4ULL}, {0x0ULL, 0x0ULL, 0xFFFFFFFBULL}, 0x0ULL, 0x1F0ULL},
  {32u, {0x61C88400ULL, 0xFFFFFF80ULL, 0x0ULL}, {0x9E377800ULL, 0x0ULL, 0xFFFFFFE0ULL}, 0x61C88000ULL, 0x9E377000ULL},
  {32u, {0xFFFFFFC1ULL, 0xFFFFFF80ULL, 0xFFFFFFFEULL}, {0x3EULL, 0x0ULL, 0x1ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0x7FFFFULL, 0xFFF9FFFFULL, 0xFFF6FFFFULL}, {0xFFF00000ULL, 0x40000ULL, 0x90000ULL}, 0xFFFFULL, 0xFFF10000ULL},
  {64u, {0x2ULL, 0xFFFFFFFFFFFFFFF0ULL, 0xFFFFFFFFFFFFFFFEULL}, {0xFFFFFFFFFFFFFFFCULL, 0x0ULL, 0x1ULL}, 0x0ULL, 0xFFFFFFFFFFFFFFE0ULL},
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
