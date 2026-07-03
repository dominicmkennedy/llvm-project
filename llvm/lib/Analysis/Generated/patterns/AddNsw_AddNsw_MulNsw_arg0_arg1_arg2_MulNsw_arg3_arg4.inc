namespace AddNsw_AddNsw_MulNsw_arg0_arg1_arg2_MulNsw_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFC03ULL, 0x25F6ULL, 0xFDFDFFFFULL, 0xFFFFFC03ULL, 0x4A88ULL}, {0x0ULL, 0xFFFFDA09ULL, 0x2020000ULL, 0x0ULL, 0xFFFFB577ULL}, 0xFC000003ULL, 0x0ULL},
  {32u, {0xFFFFFC01ULL, 0x25F6ULL, 0xFDFDFFFFULL, 0xFFFFFC01ULL, 0x4A88ULL}, {0x0ULL, 0xFFFFDA09ULL, 0x2020000ULL, 0x0ULL, 0xFFFFB577ULL}, 0xFC000001ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x93ULL, 0xFFFE0BFFULL, 0xFFFFFF00ULL, 0x122ULL}, {0x0ULL, 0xFFFFFF6CULL, 0x1F400ULL, 0x0ULL, 0xFFFFFEDDULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0xFFFFFC00ULL, 0x25F6ULL, 0xFDFDFFFFULL, 0xFFFFFC00ULL, 0x4A88ULL}, {0x0ULL, 0xFFFFDA09ULL, 0x2020000ULL, 0x0ULL, 0xFFFFB577ULL}, 0xFC000000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x97DBULL, 0xFDFDFFFFULL, 0xFFFFFF00ULL, 0x12A23ULL}, {0x0ULL, 0xFFFF6824ULL, 0x2020000ULL, 0x0ULL, 0xFFFED5DCULL}, 0xFC000003ULL, 0x0ULL},
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
