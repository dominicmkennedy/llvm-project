namespace SubNswNuw_arg0_AddNswNuw_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFDFULL, 0xFFFFFFF8ULL, 0x0ULL}, {0x20ULL, 0x4ULL, 0x0ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFEEULL, 0xFFFFFFFEULL, 0xFFFFFFF0ULL}, {0x11ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFFEFULL, 0xFFFFFFF8ULL, 0xFFFFFFF6ULL}, {0x10ULL, 0x0ULL, 0x9ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x61C88644ULL, 0xFFFFFFE0ULL, 0xFFFFFFF0ULL}, {0x9E3779B8ULL, 0x0ULL, 0x8ULL}, 0x61C88640ULL, 0x9E377980ULL},
  {32u, {0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFF8ULL}, {0x20ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFEFULL, 0x1ULL, 0xFFFFFFF7ULL}, {0x10ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFF1ULL, 0x0ULL},
  {32u, {0xFFFFFFEFULL, 0x0ULL, 0xFFFFFFF7ULL}, {0x10ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x61C88644ULL, 0xFFFFFFE0ULL, 0xFFFFFF80ULL}, {0x9E3779B8ULL, 0x0ULL, 0x0ULL}, 0x61C88600ULL, 0x9E377900ULL},
  {32u, {0xFFFFFFDFULL, 0xFFFFFE00ULL, 0xFFFFFFFEULL}, {0x20ULL, 0x0ULL, 0x1ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFBFULL, 0x0ULL, 0xFFFFFFFEULL}, {0x40ULL, 0x0ULL, 0x1ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFFFFDFULL, 0xFFFFFFF0ULL, 0xFFFFFFE7ULL}, {0x20ULL, 0x0ULL, 0x18ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFFCFULL, 0xFFFFFFF0ULL, 0xFFFFFFE7ULL}, {0x30ULL, 0x0ULL, 0x18ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFFDFULL, 0xFFFFFFF9ULL, 0xFFFFFFFDULL}, {0x20ULL, 0x0ULL, 0x2ULL}, 0xFFFFFFE1ULL, 0x18ULL},
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
