namespace MulNswNuw_SubNsw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFE1ULL, 0xFFFFFFE0ULL, 0xFFFFFFFDULL}, {0x1EULL, 0x0ULL, 0x2ULL}, 0xFFFFFFC1ULL, 0x0ULL},
  {32u, {0xFFFFF000ULL, 0xFFFF0000ULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x0ULL, 0x6ULL}, 0xFFFF8001ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFF0000ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0x3ULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFF0000ULL, 0xFFFFFF9BULL}, {0x0ULL, 0x0ULL, 0x64ULL}, 0xFF800003ULL, 0x0ULL},
  {32u, {0xFFFF8000ULL, 0xFFFF0000ULL, 0xFFFFFFF9ULL}, {0x0ULL, 0x0ULL, 0x6ULL}, 0xFFFC0001ULL, 0x0ULL},
  {32u, {0xFF800000ULL, 0xFFFE0000ULL, 0xFFFFFF9BULL}, {0x0ULL, 0x0ULL, 0x64ULL}, 0xC0000003ULL, 0x0ULL},
  {32u, {0xFFFFFFEAULL, 0xFFFFFE00ULL, 0xFFFFFFFCULL}, {0x15ULL, 0x0ULL, 0x3ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFF0000ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x0ULL, 0x2ULL}, 0xFFFFFE01ULL, 0x0ULL},
  {32u, {0xFFFFF7FFULL, 0xFFFF0000ULL, 0xFFFFBFFFULL}, {0x800ULL, 0x0ULL, 0x4000ULL}, 0xFC003FFFULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0x8000000000000000ULL, 0xFFFFFFFFFFFFFFC7ULL}, {0x0ULL, 0x0ULL, 0x38ULL}, 0xFFFFFFC000000007ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFB7ULL}, {0x0ULL, 0x0ULL, 0x48ULL}, 0xFFFFFF8000000007ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFEDFULL}, {0x0ULL, 0x0ULL, 0x120ULL}, 0xFFFFFE000000001FULL, 0x0ULL},
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
