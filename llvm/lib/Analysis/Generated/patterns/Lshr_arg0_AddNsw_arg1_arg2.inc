namespace Lshr_arg0_AddNsw_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFF0000ULL, 0x0ULL, 0xFFFFFFEFULL}, {0xFFFFULL, 0x80000000ULL, 0x10ULL}, 0xFFFF0000ULL, 0x1ULL},
  {32u, {0x1ULL, 0xFFFFFFE0ULL, 0x2ULL}, {0x0ULL, 0x10ULL, 0xFFFFFFFDULL}, 0xFFF80000ULL, 0x0ULL},
  {32u, {0xFFFFFF7FULL, 0xFFFFFFF8ULL, 0xFFFFFFFEULL}, {0x80ULL, 0x0ULL, 0x1ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE8ULL, 0x5ULL}, {0x0ULL, 0x10ULL, 0xFFFFFFFAULL}, 0xFFC00000ULL, 0x0ULL},
  {32u, {0x0ULL, 0x80000000ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x1ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE8ULL, 0x4ULL}, {0x0ULL, 0x10ULL, 0xFFFFFFFBULL}, 0xFFE00000ULL, 0x0ULL},
  {32u, {0xFEULL, 0xFFFFFFF0ULL, 0x7ULL}, {0xFFFFFF01ULL, 0x0ULL, 0xFFFFFFF8ULL}, 0x0ULL, 0x1FFFF00ULL},
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0x80000003ULL}, {0x0ULL, 0x10ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0x80000000ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x10ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFEFFFFULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL}, {0x10000ULL, 0x0ULL, 0x1ULL}, 0xFFFF3FFFULL, 0x0ULL},
  {64u, {0x8000000000000000ULL, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL}, {0x0ULL, 0x4ULL, 0xFFFFFFFFFFFFFFFFULL}, 0xF000000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL}, {0x1ULL, 0x4ULL, 0xFFFFFFFFFFFFFFFFULL}, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
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
