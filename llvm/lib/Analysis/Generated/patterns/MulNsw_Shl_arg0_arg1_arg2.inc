namespace MulNsw_Shl_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0x0ULL}, {0x1ULL, 0x0ULL, 0xFFFFFFFFULL}, 0x0ULL, 0xC0000000ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0xFFFFFFFDULL}, {0x1ULL, 0x0ULL, 0x2ULL}, 0x80000001ULL, 0x0ULL},
  {32u, {0xFFFFFFF7ULL, 0x0ULL, 0xFFFFF82FULL}, {0x8ULL, 0x0ULL, 0x7D0ULL}, 0x8000007FULL, 0x0ULL},
  {32u, {0xFFFFFFF7ULL, 0x0ULL, 0xFFFFC94FULL}, {0x8ULL, 0x0ULL, 0x36B0ULL}, 0x8000007FULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0xFFFFFFE1ULL}, {0x1ULL, 0x0ULL, 0x1EULL}, 0x80000001ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0x80000003ULL}, {0x1ULL, 0x0ULL, 0x0ULL}, 0x80000003ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFE0ULL, 0xFFFFFFEFULL}, {0x1ULL, 0x0ULL, 0x10ULL}, 0x8000000FULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0xFFFFFFFCULL}, {0x1ULL, 0x0ULL, 0x3ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0xFFFFFFF8ULL}, {0x1ULL, 0x0ULL, 0x7ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x1ULL, 0x0ULL, 0x8ULL}, 0x80000007ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0x0ULL, 0xFFFFFFFFFF7FFFFFULL}, {0x1ULL, 0x0ULL, 0x800000ULL}, 0x80000000007FFFFFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFFDULL}, {0x1ULL, 0x0ULL, 0x2ULL}, 0x8000000000000001ULL, 0x0ULL},
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
