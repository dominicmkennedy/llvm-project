namespace AddNswNuw_Smin_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x80000000ULL, 0xFFFFFF3CULL, 0xFFFFFFC3ULL}, {0x0ULL, 0xC3ULL, 0x3CULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFBFFULL, 0xFFFFFFBFULL}, {0x0ULL, 0x400ULL, 0x40ULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFE0BULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1F4ULL, 0x1ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFF3FULL, 0xFFFFFFEFULL}, {0x0ULL, 0xC0ULL, 0x10ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFBFFFE0ULL, 0xFFFFFFDFULL}, {0x0ULL, 0x40001FULL, 0x20ULL}, 0xFF800000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFF9BULL, 0xFFFFFFFEULL}, {0x0ULL, 0x64ULL, 0x1ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFDFULL, 0xFFFFFFEFULL}, {0x0ULL, 0x20ULL, 0x10ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFFBULL, 0xFFFFFFFEULL}, {0x0ULL, 0x4ULL, 0x1ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFF7FFULL, 0xFFFFFFFDULL}, {0x0ULL, 0x800ULL, 0x0ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFF7FULL, 0xFFFFFFFBULL}, {0x0ULL, 0x80ULL, 0x4ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFEFULL, 0xFFFFFFFEULL}, {0x0ULL, 0x10ULL, 0x1ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFF7FULL, 0xFFFFFFFCULL}, {0x0ULL, 0x80ULL, 0x3ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFFFFFE8ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x17ULL, 0x1ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFF3ULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0xCULL, 0x2ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0xAULL, 0x1ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
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
