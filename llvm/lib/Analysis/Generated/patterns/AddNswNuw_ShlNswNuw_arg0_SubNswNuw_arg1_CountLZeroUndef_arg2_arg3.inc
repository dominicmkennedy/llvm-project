namespace AddNswNuw_ShlNswNuw_arg0_SubNswNuw_arg1_CountLZeroUndef_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFFEULL, 0xFFFFFFDFULL, 0xFFFF8000ULL, 0xFFFF8000ULL}, {0x1ULL, 0x20ULL, 0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFFFDULL, 0xFFFFFFDFULL, 0xFFFFFF00ULL, 0xFFFF8000ULL}, {0x2ULL, 0x20ULL, 0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFF8000ULL}, {0x1ULL, 0x20ULL, 0x0ULL, 0x7FFFULL}, 0x80000000ULL, 0x1ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFDFULL, 0xFFFFF800ULL, 0xFFFF8000ULL}, {0x1ULL, 0x20ULL, 0x0ULL, 0x7FFFULL}, 0xFFFF7800ULL, 0x8001ULL},
  {32u, {0xFFFFFFFEULL, 0xFFFFFFDFULL, 0xFFFFFC00ULL, 0xFFFF8000ULL}, {0x1ULL, 0x20ULL, 0x0ULL, 0x7FFFULL}, 0xFFFF7C00ULL, 0x8001ULL},
  {64u, {0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFFFFBFULL, 0xFFFFFFFFFFFFFE00ULL, 0xFFFFFFFFFFFFFF4BULL}, {0x14ULL, 0x40ULL, 0x0ULL, 0xB4ULL}, 0xFFFFFFFFFFFFC003ULL, 0x4ULL},
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
