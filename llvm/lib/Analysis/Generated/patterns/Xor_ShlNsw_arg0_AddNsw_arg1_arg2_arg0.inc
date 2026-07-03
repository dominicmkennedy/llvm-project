namespace Xor_ShlNsw_arg0_AddNsw_arg1_arg2_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0x1ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFEULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0x0ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE0ULL, 0x1ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFEULL}, 0xE0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF1ULL, 0x0ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFULL}, 0xFFFFE000ULL, 0x1ULL},
  {32u, {0x0ULL, 0xFFFFFFF1ULL, 0x2ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFDULL}, 0xFFFFF800ULL, 0x1ULL},
  {32u, {0x0ULL, 0xFFFFFFF1ULL, 0x0ULL}, {0xFFFFFFFFULL, 0x8ULL, 0xFFFFFFFFULL}, 0xFFFFE000ULL, 0x7FULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0x3ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFCULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0x80000000ULL, 0xFFFFFFFDULL}, {0xFFFFFFFFULL, 0x0ULL, 0x2ULL}, 0x80000000ULL, 0x3ULL},
  {32u, {0x0ULL, 0xFFFFFFF0ULL, 0x4ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFBULL}, 0xFFFFFC00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE0ULL, 0x7ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFF8ULL}, 0xFF800000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF0ULL, 0x6ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFF9ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE0ULL, 0x0ULL}, {0xFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFULL}, 0xC0000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC0ULL, 0x2ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFDULL}, 0xF000000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL}, 0xC000000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x20ULL, 0xFFFFFFFFFFFFFFFFULL}, 0xC000000000000000ULL, 0x7FFFFFFFULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFC7ULL, 0x0ULL}, {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL}, 0xFF80000000000000ULL, 0x7FULL},
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
