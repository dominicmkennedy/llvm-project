namespace AddNswNuw_AddNswNuw_AddNswNuw_MulNswNuw_arg0_arg1_MulNswNuw_arg2_arg3_MulNswNuw_arg4_arg5_MulNswNuw_arg6_arg7 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[8], argO[8], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFF00ULL, 0xFFF1ULL, 0xFF00ULL, 0xFFF8ULL, 0xFF00ULL, 0xFFF0ULL, 0xFF00ULL, 0xFFE3ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xC000ULL, 0x0ULL},
  {16u, {0xFF00ULL, 0xFFF8ULL, 0xFF00ULL, 0xFFF1ULL, 0xFF00ULL, 0xFFF0ULL, 0xFF00ULL, 0xFFE3ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xC000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFF6FULL, 0xFFFFFF00ULL, 0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x90ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFF000FULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFFFF6FULL, 0xFFFFFF00ULL, 0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x90ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFFFF6FULL, 0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFFEFULL, 0xFFFFFF00ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x90ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFF000FULL, 0x0ULL},
  {32u, {0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFFFF6FULL, 0xFFFFFF00ULL, 0xFFFFFFCFULL, 0xFFFFFFEFULL, 0xFFFFFF00ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x90ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFF000FULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFF6FULL, 0xFFFFFFCFULL, 0xFFFFFF00ULL, 0xFFFFFF00ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x90ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xFFFF000FULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFE6ULL, 0xFFFFFF00ULL, 0xFFFFFFE5ULL, 0xFFFFFF00ULL, 0xFFFFFFCCULL, 0xFFFFFF00ULL, 0xFFFFFFE5ULL}, {0x0ULL, 0x19ULL, 0x0ULL, 0x1AULL, 0x0ULL, 0x33ULL, 0x0ULL, 0x1AULL}, 0xFFFF8000ULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0xE7FFFFFAULL, 0xFFFF8000ULL, 0xFCFFFFFAULL, 0xFFFF8000ULL, 0xF9FFFFE8ULL, 0xFFFF8000ULL, 0xF3FFFFECULL}, {0x0ULL, 0x18000005ULL, 0x0ULL, 0x3000005ULL, 0x0ULL, 0x6000017ULL, 0x0ULL, 0xC000013ULL}, 0x80FFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xF9FFFFE8ULL, 0x0ULL, 0xFCFFFFFAULL, 0xFFFF8000ULL, 0xF3FFFFECULL, 0xFFFFFFFCULL, 0xE7FFFFFAULL}, {0x0ULL, 0x6000017ULL, 0x0ULL, 0x3000005ULL, 0x0ULL, 0xC000013ULL, 0x0ULL, 0x18000005ULL}, 0x80FFFE00ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFE7FFFFULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFE7FFFFFFULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFE7FFULL, 0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFE7ULL}, {0x0ULL, 0x180000ULL, 0x0ULL, 0x18000000ULL, 0x0ULL, 0x1800ULL, 0x0ULL, 0x18ULL}, 0xFFFFFFE000000007ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4, std::array<APInt, 2> ssa_5, std::array<APInt, 2> ssa_6, std::array<APInt, 2> ssa_7) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64 || ssa_5[0].getBitWidth() > 64 || ssa_6[0].getBitWidth() > 64 || ssa_7[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[8], inO[8];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  inZ[2] = ssa_2[0].getZExtValue();
  inO[2] = ssa_2[1].getZExtValue();
  inZ[3] = ssa_3[0].getZExtValue();
  inO[3] = ssa_3[1].getZExtValue();
  inZ[4] = ssa_4[0].getZExtValue();
  inO[4] = ssa_4[1].getZExtValue();
  inZ[5] = ssa_5[0].getZExtValue();
  inO[5] = ssa_5[1].getZExtValue();
  inZ[6] = ssa_6[0].getZExtValue();
  inO[6] = ssa_6[1].getZExtValue();
  inZ[7] = ssa_7[0].getZExtValue();
  inO[7] = ssa_7[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 8; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
