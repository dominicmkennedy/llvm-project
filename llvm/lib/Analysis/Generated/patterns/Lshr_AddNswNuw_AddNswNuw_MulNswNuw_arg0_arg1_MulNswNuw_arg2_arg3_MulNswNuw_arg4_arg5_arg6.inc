namespace Lshr_AddNswNuw_AddNswNuw_MulNswNuw_arg0_arg1_MulNswNuw_arg2_arg3_MulNswNuw_arg4_arg5_arg6 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[7], argO[7], outZ, outO; };
static constexpr Entry kEntries[] = {
  {24u, {0xFFFF00ULL, 0xFFFFB2ULL, 0xFFFF00ULL, 0xFFFF68ULL, 0xFFFF00ULL, 0xFFFFE3ULL, 0xFFFFF7ULL}, {0x0ULL, 0x4DULL, 0x0ULL, 0x97ULL, 0x0ULL, 0x1CULL, 0x8ULL}, 0xFFFF00ULL, 0x0ULL},
  {24u, {0xFFFF00ULL, 0xFFFFE3ULL, 0xFFFF00ULL, 0xFFFFB2ULL, 0xFFFF00ULL, 0xFFFF68ULL, 0xFFFFF7ULL}, {0x0ULL, 0x1CULL, 0x0ULL, 0x4DULL, 0x0ULL, 0x97ULL, 0x8ULL}, 0xFFFF00ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFF69ULL, 0xFFFF0000ULL, 0xFFFFFFB2ULL, 0xFFFF0000ULL, 0xFFFFFFE2ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x96ULL, 0x0ULL, 0x4DULL, 0x0ULL, 0x1DULL, 0x8ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFF6922ULL, 0xFFFFFF00ULL, 0xFFFFE2B3ULL, 0xFFFFFF00ULL, 0xFFFFB327ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x96DDULL, 0x0ULL, 0x1D4CULL, 0x0ULL, 0x4CD8ULL, 0x8ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFB327ULL, 0xFFFFFF00ULL, 0xFFFF6922ULL, 0xFFFFFF00ULL, 0xFFFFE2B3ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x4CD8ULL, 0x0ULL, 0x96DDULL, 0x0ULL, 0x1D4CULL, 0x8ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFB2ULL, 0xFFFFFF00ULL, 0xFFFFFF69ULL, 0xFFFFFF00ULL, 0xFFFFFFE2ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x4DULL, 0x0ULL, 0x96ULL, 0x0ULL, 0x1DULL, 0x8ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFF69ULL, 0xFFFFFF00ULL, 0xFFFFFFB2ULL, 0xFFFFFF00ULL, 0xFFFFFFE2ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x96ULL, 0x0ULL, 0x4DULL, 0x0ULL, 0x1DULL, 0x8ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFFB2ULL, 0xFFFF0000ULL, 0xFFFFFF69ULL, 0xFFFF0000ULL, 0xFFFFFFE2ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x4DULL, 0x0ULL, 0x96ULL, 0x0ULL, 0x1DULL, 0x8ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFB2ULL, 0xFFFFFF00ULL, 0xFFFFFF68ULL, 0xFFFFFF00ULL, 0xFFFFFFE3ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x4DULL, 0x0ULL, 0x97ULL, 0x0ULL, 0x1CULL, 0x8ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFF00FF00ULL, 0xFFFFFFF0ULL, 0xFF00FF00ULL, 0xFFFFFFF8ULL, 0xFF00FF00ULL, 0xFFFFFFF8ULL, 0xFFFFFFF8ULL}, {0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL}, 0xE0000000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFF68ULL, 0xFFFFFF00ULL, 0xFFFFFFE3ULL, 0xFFFFFF00ULL, 0xFFFFFFB2ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x97ULL, 0x0ULL, 0x1CULL, 0x0ULL, 0x4DULL, 0x8ULL}, 0xFFFFFF00ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4, std::array<APInt, 2> ssa_5, std::array<APInt, 2> ssa_6) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64 || ssa_5[0].getBitWidth() > 64 || ssa_6[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[7], inO[7];
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
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 7; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
