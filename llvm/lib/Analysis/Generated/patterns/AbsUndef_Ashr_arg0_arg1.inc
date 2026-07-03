namespace AbsUndef_Ashr_arg0_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x10ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x3ULL}, 0xE0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE8ULL}, {0x0ULL, 0x17ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL}, {0x0ULL, 0x18ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0xC0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE3ULL}, {0x0ULL, 0x1CULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x8ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFBULL}, {0x0ULL, 0x4ULL}, 0xF0000000ULL, 0x0ULL},
  {32u, {0xFFFFFFULL, 0xFFFFFFEAULL}, {0x0ULL, 0x15ULL}, 0xFFFFF807ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x20ULL}, 0xFFFFFFFF00000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF9ULL}, {0x0ULL, 0x6ULL}, 0xFC00000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFAULL}, {0x0ULL, 0x5ULL}, 0xF800000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFCULL}, {0x0ULL, 0x3ULL}, 0xE000000000000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0xC000000000000000ULL, 0x0ULL},
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
