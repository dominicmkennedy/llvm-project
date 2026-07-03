namespace AddNsw_Select_ICmpUlt_arg0_arg1_arg2_AddNswNuw_Umin_arg0_arg3_arg4_arg5 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[6], argO[6], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFFF00CULL, 0xFFFFFFFFFFFFFFF2ULL, 0x0ULL}, {0x0ULL, 0x14ULL, 0x20ULL, 0xFF3ULL, 0xDULL, 0xFFFFFFFFFFFFFFFFULL}, 0xFFFFFFFFFFFFF000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFC000CULL, 0xFFFFFFFFFFFFFFF2ULL, 0x0ULL}, {0x0ULL, 0x14ULL, 0x20ULL, 0x3FFF3ULL, 0xDULL, 0xFFFFFFFFFFFFFFFFULL}, 0xFFFFFFFFFFFC0000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFFFDFFULL, 0xFFFFFFFFFFFFFFF2ULL, 0x0ULL}, {0x0ULL, 0x14ULL, 0x20ULL, 0x200ULL, 0xDULL, 0xFFFFFFFFFFFFFFFFULL}, 0xFFFFFFFFFFFFFC00ULL, 0x0ULL},
  {64u, {0xDULL, 0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFC000CULL, 0xFFFFFFFFFFFFFFF2ULL, 0x0ULL}, {0x12ULL, 0x14ULL, 0x20ULL, 0x3FFF3ULL, 0xDULL, 0xFFFFFFFFFFFFFFFFULL}, 0xFFFFFFFFFFFC0000ULL, 0x1EULL},
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
