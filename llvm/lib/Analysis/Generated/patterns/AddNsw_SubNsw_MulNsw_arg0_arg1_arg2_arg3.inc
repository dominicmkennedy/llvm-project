namespace AddNsw_SubNsw_MulNsw_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFFCULL, 0x2ULL, 0xFFFFFFF0ULL, 0xFFFFFFE6ULL}, {0x0ULL, 0xFFFFFFFDULL, 0x0ULL, 0x19ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x3ULL, 0xFFFFFFC0ULL, 0x800ULL}, {0x0ULL, 0xFFFFFFFCULL, 0x0ULL, 0xFFFFF7FFULL}, 0x800ULL, 0xFFFFF000ULL},
  {32u, {0xFFFFFF00ULL, 0x3ULL, 0xFFFFFFFCULL, 0x800ULL}, {0x0ULL, 0xFFFFFFFCULL, 0x0ULL, 0xFFFFF7FFULL}, 0x800ULL, 0xFFFFF400ULL},
  {64u, {0xFFFFFFFFFFFFE000ULL, 0x12ULL, 0xFFF8000000000000ULL, 0xFFF0000000000025ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFEDULL, 0x0ULL, 0xFFFFFFFFFFFDAULL}, 0xFFF0000000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFE000ULL, 0x12ULL, 0xFFF0000000000000ULL, 0xFFE000000000004BULL}, {0x0ULL, 0xFFFFFFFFFFFFFFEDULL, 0x0ULL, 0x1FFFFFFFFFFFB4ULL}, 0xFFE0000000000000ULL, 0x0ULL},
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
