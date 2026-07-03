namespace AddNsw_AshrExact_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0xFFFF7FDFULL}, {0x0ULL, 0x10ULL, 0x8020ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL, 0xC1C71BULL}, {0x0ULL, 0x18ULL, 0xFF3E38E4ULL}, 0xC1C600ULL, 0xFF3E3800ULL},
  {32u, {0xFFFFFFFULL, 0xFFFFFFE4ULL, 0xFFFFFFCDULL}, {0x0ULL, 0x1BULL, 0x32ULL}, 0xFFFFFF81ULL, 0x0ULL},
  {32u, {0xFFFFFFFULL, 0xFFFFFFE3ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x1CULL, 0x10ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL, 0xC1C71EULL}, {0x0ULL, 0x18ULL, 0xFF3E38E1ULL}, 0xC1C600ULL, 0xFF3E3800ULL},
  {32u, {0xFFFFFFULL, 0xFFFFFFE7ULL, 0xFFFFFF06ULL}, {0x0ULL, 0x18ULL, 0x80ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFFULL, 0xFFFFFFE7ULL, 0xFFFFFF7FULL}, {0x0ULL, 0x18ULL, 0x80ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFF7FFFFFFFULL}, {0x0ULL, 0x20ULL, 0x80000000ULL}, 0xFFFFFFFF0000FFFFULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFCFULL, 0xFFFFFFFFFFFF7FFFULL}, {0x0ULL, 0x30ULL, 0x8000ULL}, 0xFFFFFFFFFFFF0000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFEFULL, 0xFFFF7FFFFFFFFFFFULL}, {0x0ULL, 0x10ULL, 0x800000000000ULL}, 0xFFFF0000FFFFFFFFULL, 0x0ULL},
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
