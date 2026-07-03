namespace AddNsw_Select_ICmpSlt_arg0_arg1_arg2_arg0_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xFFFFD8E8ULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0x2717ULL, 0xFFFFFFFFULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFFFULL, 0x80000000ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF7ULL, 0x0ULL}, {0x0ULL, 0x8ULL, 0x8ULL, 0xFFFFFFFFULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFDFULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0x20ULL, 0xFFFFFFFFULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0xFFFFFFEFULL, 0xFULL}, {0x0ULL, 0x10ULL, 0x10ULL, 0xFFFFFFF0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL, 0x80000000ULL}, {0x0ULL, 0x1ULL, 0x1ULL, 0x0ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFF9ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x6ULL, 0x1ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFDULL, 0x0ULL}, {0x0ULL, 0x2ULL, 0x2ULL, 0xFFFFFFFFULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFBEULL, 0xFFFFFFBEULL, 0x40ULL}, {0x0ULL, 0x41ULL, 0x41ULL, 0xFFFFFFBFULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFF9EULL, 0xFFFFFF9EULL, 0x60ULL}, {0x0ULL, 0x61ULL, 0x61ULL, 0xFFFFFF9FULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFFULL, 0xFFFFFFF8ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x7ULL, 0x1ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0x1FULL, 0x1FULL, 0xFFFFFFDFULL}, {0x0ULL, 0xFFFFFFE0ULL, 0xFFFFFFE0ULL, 0x20ULL}, 0x80000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFEFFFULL, 0x0ULL}, {0x0ULL, 0x1ULL, 0x1000ULL, 0xFFFFFFFFFFFFFFFFULL}, 0x8000000000000000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[4], inO[4];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  inZ[3] = ssa_3[0].getZExtValue();
  inO[3] = ssa_3[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 4; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
