namespace AddNswNuw_AddNsw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFF80ULL, 0x0ULL, 0xFF80ULL}, {0x0ULL, 0xFFFFULL, 0x40ULL}, 0xFF00ULL, 0x0ULL},
  {32u, {0xFC9003FFULL, 0x35FDBFFULL, 0xFFFF2000ULL}, {0x3600000ULL, 0xFCA02400ULL, 0xDC00ULL}, 0xFFE00000ULL, 0x0ULL},
  {32u, {0xFFFFCE3FULL, 0x307FULL, 0xFFFFFF40ULL}, {0x3000ULL, 0xFFFFCF80ULL, 0x80ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x1ULL, 0xFFFFFFFCULL}, {0x0ULL, 0xFFFFFFFEULL, 0x3ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0xFFFFFF9EULL, 0x9ULL, 0xFFFFFFE0ULL}, {0x41ULL, 0xFFFFFFF6ULL, 0x0ULL}, 0xFFFFFF80ULL, 0x0ULL},
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
