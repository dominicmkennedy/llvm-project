namespace MulNsw_Sdiv_arg0_arg1_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFFDULL, 0x0ULL}, {0x2ULL, 0x0ULL}, 0xFFFFFFFDULL, 0x0ULL},
  {32u, {0xFFFFFFF8ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFFFEULL, 0x0ULL},
  {32u, {0xFFFFFFF0ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFECED2FFULL, 0x0ULL}, {0x1312D00ULL, 0x0ULL}, 0xFE000000ULL, 0x0ULL},
  {32u, {0xFFFFEFFFULL, 0x0ULL}, {0x1000ULL, 0x0ULL}, 0xFFFFE000ULL, 0x0ULL},
  {32u, {0xFFFFFF80ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0xFFFFFE00ULL, 0x0ULL}, {0x0ULL, 0x0ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFF0BDBFULL, 0x0ULL}, {0xF4240ULL, 0x0ULL}, 0xFFF00000ULL, 0x0ULL},
  {32u, {0xFF67697FULL, 0x0ULL}, {0x989680ULL, 0x0ULL}, 0xFF000000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFF0000ULL}, {0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
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
