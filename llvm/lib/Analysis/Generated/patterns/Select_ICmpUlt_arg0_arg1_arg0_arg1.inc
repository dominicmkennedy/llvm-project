namespace Select_ICmpUlt_arg0_arg1_arg0_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFC3ULL, 0x0ULL}, {0x3CULL, 0x0ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x2ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFC0000ULL}, {0x0ULL, 0x0ULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFC000000ULL}, {0x0ULL, 0x0ULL}, 0xFC000000ULL, 0x0ULL},
  {32u, {0xFFFFFEFEULL, 0x0ULL}, {0x101ULL, 0x0ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFC000ULL}, {0x0ULL, 0x0ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFF000001ULL}, {0x0ULL, 0xFFFFFEULL}, 0xFF000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFCULL, 0x0ULL}, {0x3ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0xFFFFFFFFDFFFFFFFULL, 0x0ULL}, {0x20000000ULL, 0x0ULL}, 0xFFFFFFFFC0000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFF0BDBFULL}, {0x0ULL, 0xF4240ULL}, 0xFFFFFFFFFFF00000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFC0000000ULL}, {0x0ULL, 0x3FFFFFFFULL}, 0xFFFFFFFFC0000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFF000000ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFFFFFF000000ULL, 0x0ULL},
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
