namespace Select_ICmpUle_arg0_arg1_arg2_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFF0000ULL, 0x0ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFEEFFFFULL, 0x0ULL, 0xFFFF0002ULL}, {0x110000ULL, 0x0ULL, 0xFFFDULL}, 0xFFE00000ULL, 0x0ULL},
  {32u, {0xFFFFFFBFULL, 0x0ULL, 0xFFFFFFC0ULL}, {0x40ULL, 0x0ULL, 0x3FULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFFFF9FULL, 0x0ULL, 0xFFFFFFA0ULL}, {0x60ULL, 0x0ULL, 0x5FULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0xFFFFFEFFULL, 0x0ULL, 0xFFFFFF00ULL}, {0x100ULL, 0x0ULL, 0xFFULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFBFFULL, 0x0ULL, 0xFFFFFBFFULL}, {0x400ULL, 0x0ULL, 0x400ULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFE0ULL}, {0x20ULL, 0x0ULL, 0x1FULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xF8000000ULL, 0x0ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xF8000000ULL, 0x0ULL},
  {32u, {0xFFFFFFEBULL, 0x0ULL, 0xFFFFFFEBULL}, {0x14ULL, 0x0ULL, 0x14ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFEFULL, 0x0ULL, 0xFFFFFFFFFFFFFFEFULL}, {0x10ULL, 0x0ULL, 0x10ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFBFFULL, 0x0ULL, 0xFFFFFFFFFFFFFBFFULL}, {0x400ULL, 0x0ULL, 0x400ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFEFFFULL, 0x0ULL, 0xFFFFFFFFFFFFEFFFULL}, {0x1000ULL, 0x0ULL, 0x1000ULL}, 0xFFFFFFFFFFFFE000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0x0ULL, 0xFFFFFFFF00000000ULL}, {0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFFFFFF00000000ULL, 0x0ULL},
  {64u, {0xFFFFFFF000000000ULL, 0x0ULL, 0xFFFFFFF000000001ULL}, {0xFFFFFFFFFULL, 0x3FULL, 0xFFFFFFFFEULL}, 0xFFFFFFF000000000ULL, 0x3EULL},
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
