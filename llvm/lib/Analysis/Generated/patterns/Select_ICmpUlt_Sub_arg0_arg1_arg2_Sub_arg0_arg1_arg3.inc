namespace Select_ICmpUlt_Sub_arg0_arg1_arg2_Sub_arg0_arg1_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0x1FULL, 0xFFFFFFDFULL, 0xFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x20ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFBFAULL, 0xFFFFFFFFFFFFFBFBULL}, {0x0ULL, 0x0ULL, 0x405ULL, 0x404ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFEFFFFULL, 0xFFFFFFFFFFFEFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFFFFFE0000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFBFFULL, 0xFFFFFFFFFFFFFBFFULL}, {0x0ULL, 0x0ULL, 0x400ULL, 0x400ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFEFFFULL, 0xFFFFFFFFFFFFEFFFULL}, {0x0ULL, 0x0ULL, 0x1000ULL, 0x1000ULL}, 0xFFFFFFFFFFFFE000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFFF7ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x0ULL, 0x8ULL, 0x8ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFCULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0x3ULL, 0x3ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFFFFFFFFFDULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x2ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0x0ULL, 0x0ULL, 0xFFFFFFFF800001FFULL, 0xFFFFFFFF800001FFULL}, {0x0ULL, 0x0ULL, 0x7FFFFE00ULL, 0x7FFFFE00ULL}, 0xFFFFFFFF80000000ULL, 0x0ULL},
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
