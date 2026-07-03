namespace SubNswNuw_arg0_CountLZero_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFFEFULL, 0xFF00ULL}, {0x10ULL, 0x0ULL}, 0xFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFFDFULL, 0x80000000ULL}, {0x20ULL, 0x0ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFDEULL, 0xC0000000ULL}, {0x20ULL, 0x0ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFDFULL, 0xFFFF8000ULL}, {0x20ULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x0ULL, 0x0ULL}, {0xFFFFFFE0ULL, 0x0ULL}, 0x0ULL, 0xFFFFFFC0ULL},
  {64u, {0xFFFFFFFFFFFFFFBFULL, 0x8000000000000000ULL}, {0x40ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFBFULL, 0xFFFFFFFF80000000ULL}, {0x40ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFC01ULL, 0x0ULL}, {0x3FEULL, 0x0ULL}, 0xFFFFFFFFFFFFFC00ULL, 0x380ULL},
  {64u, {0xFFFFFFFFFFFFFFBFULL, 0xFFFFFFFFFFFFFFC0ULL}, {0x40ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
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
