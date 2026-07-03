namespace Lshr_Shl_arg0_arg1_SubNswNuw_arg2_Select_arg3_arg4_arg5 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[6], argO[6], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFAULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x3ULL, 0x5ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFF5ULL, 0xFFFFFFF3ULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0xAULL, 0xCULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x7ULL, 0x4ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x8ULL, 0x2ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x2ULL, 0x3ULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFEULL, 0xFFFFFFFDULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x1ULL, 0x2ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x8ULL, 0x10ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x2ULL, 0x8ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x2ULL, 0x1ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFBULL, 0xFFFFFFF8ULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x4ULL, 0x7ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFDFULL, 0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x20ULL, 0x0ULL, 0x3ULL, 0x4ULL}, 0xFFFFFFF0ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4, std::array<APInt, 2> ssa_5) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64 || ssa_5[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[6], inO[6];
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
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 6; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
