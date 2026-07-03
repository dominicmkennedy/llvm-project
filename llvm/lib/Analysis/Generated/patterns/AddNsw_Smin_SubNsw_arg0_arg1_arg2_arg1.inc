namespace AddNsw_Smin_SubNsw_arg0_arg1_arg2_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFF0000ULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFC0ULL, 0xFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0x80000000ULL, 0xFFFFFE07ULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFFFF7ULL, 0x80000000ULL, 0xFFFFFFC0ULL}, {0x8ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0x80000000ULL, 0xFFFFFFC0ULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0x8000000000000003ULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x4ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0x8000000000000007ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x0ULL, 0x8ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0x8000000000000000ULL, 0xFFFFFFFFFFFFDFBFULL}, {0x0ULL, 0x0ULL, 0x2040ULL}, 0x8000000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFBULL, 0x8000000000000007ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x4ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFFFFFFFFFFBULL, 0x4ULL},
  {64u, {0xFFFFFFFFFFFFFFFDULL, 0x8000000000000007ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x2ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFFFFFFFFFFDULL, 0x2ULL},
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
