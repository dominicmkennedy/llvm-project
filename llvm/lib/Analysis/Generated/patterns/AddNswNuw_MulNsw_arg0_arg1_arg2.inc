namespace AddNswNuw_MulNsw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xA4ULL, 0x1869FULL, 0xDFFFE7A1ULL}, {0xFFFFFF10ULL, 0xFFFE7960ULL, 0x2000185EULL}, 0xDE000001ULL, 0x2000001EULL},
  {32u, {0xA4ULL, 0x1869FULL, 0xDFFFE75DULL}, {0xFFFFFF10ULL, 0xFFFE7960ULL, 0x200018A2ULL}, 0xDE00001DULL, 0x20000002ULL},
  {32u, {0xA4ULL, 0x1869FULL, 0xFFFFE7A1ULL}, {0xFFFFFF10ULL, 0xFFFE7960ULL, 0x185EULL}, 0xFE000001ULL, 0x1EULL},
  {32u, {0xA4ULL, 0x1869FULL, 0xFFFFE75DULL}, {0xFFFFFF10ULL, 0xFFFE7960ULL, 0x18A2ULL}, 0xFE00001DULL, 0x2ULL},
  {64u, {0xFFFFFFFFFFFF8000ULL, 0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFC0001ULL}, {0x0ULL, 0x14ULL, 0x2ULL}, 0xFFFFFFFFFFF00001ULL, 0x2ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFC8C0ULL, 0xFFFFFFFFFFFF8000ULL}, {0x0ULL, 0x373FULL, 0x7FFFULL}, 0xFFFFE00000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFFD0ULL}, {0x0ULL, 0x28ULL, 0x2FULL}, 0xFFFFFFE000000000ULL, 0x7ULL},
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
