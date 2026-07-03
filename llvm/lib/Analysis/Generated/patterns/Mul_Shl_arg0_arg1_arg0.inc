namespace Mul_Shl_arg0_arg1_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1ULL}, 0x5ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0xBULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL}, {0x0ULL, 0x7ULL}, 0x17FULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFAULL}, {0x0ULL, 0x5ULL}, 0x5FULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF5ULL}, {0x0ULL, 0xAULL}, 0xBFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x10ULL}, 0x2FFFFULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL}, 0x17ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x1ULL}, 0x5ULL, 0x0ULL},
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
