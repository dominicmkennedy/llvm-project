namespace AddNswNuw_Lshr_MulNswNuw_SubNswNuw_arg0_arg1_arg2_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFFDFULL, 0x0ULL, 0xFFFFFB2EULL, 0xFFFFFFF3ULL, 0xFFFFFFFEULL}, {0x20ULL, 0x0ULL, 0x4D1ULL, 0xCULL, 0x0ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFFBFULL, 0x0ULL, 0xFFFFFB2EULL, 0xFFFFFFF3ULL, 0xFFFFFFFEULL}, {0x40ULL, 0x0ULL, 0x4D1ULL, 0xCULL, 0x0ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0xFFFFFEFFULL, 0x0ULL, 0xFFFFFF00ULL, 0xFFFFFFF7ULL, 0xFFFFFF00ULL}, {0x100ULL, 0x0ULL, 0x0ULL, 0x8ULL, 0x0ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFF7FULL, 0xFFFFFF80ULL, 0xFFFFFB2EULL, 0xFFFFFFF3ULL, 0xFFFFFFFEULL}, {0x80ULL, 0x0ULL, 0x4D1ULL, 0xCULL, 0x1ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFEF3EEBFULL, 0xFFFFFFF800000000ULL, 0xFFFFFFF800000000ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFCDBC081FULL}, {0x10C1140ULL, 0x0ULL, 0x0ULL, 0x18ULL, 0x3243F7E0ULL}, 0xFFFFFFF000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFEF3EEBFULL, 0x0ULL, 0xFFFFFFF000000000ULL, 0xFFFFFFFFFFFFFFE7ULL, 0xFFFFFFFFCDBC081FULL}, {0x10C1140ULL, 0x0ULL, 0x0ULL, 0x18ULL, 0x3243F7E0ULL}, 0xFFFFFFE000000000ULL, 0x0ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1, std::array<APInt, 2> ssa_2, std::array<APInt, 2> ssa_3, std::array<APInt, 2> ssa_4) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64 || ssa_2[0].getBitWidth() > 64 || ssa_3[0].getBitWidth() > 64 || ssa_4[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[5], inO[5];
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
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 5; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
