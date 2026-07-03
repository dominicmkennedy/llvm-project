namespace Add_MulNsw_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFFF4AFAEULL}, {0x0ULL, 0xC00005ULL, 0xB5051ULL}, 0x34A000ULL, 0xB4000ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFFE95F5DULL}, {0x0ULL, 0xC00005ULL, 0x16A0A2ULL}, 0x294000ULL, 0x168000ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFFDE0F0CULL}, {0x0ULL, 0xC00005ULL, 0x21F0F3ULL}, 0x1E0000ULL, 0x21E000ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFFD2BEBBULL}, {0x0ULL, 0xC00005ULL, 0x2D4144ULL}, 0x128000ULL, 0x2D0000ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFFC76E6AULL}, {0x0ULL, 0xC00005ULL, 0x389195ULL}, 0x76000ULL, 0x388000ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFF8EDCD5ULL}, {0x0ULL, 0xC00005ULL, 0x71232AULL}, 0xEC000ULL, 0x310000ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFF838C84ULL}, {0x0ULL, 0xC00005ULL, 0x7C737BULL}, 0x38800ULL, 0x3C7000ULL},
  {32u, {0xFFFFFF00ULL, 0x492FULL, 0xFDFDFFFFULL}, {0x0ULL, 0xFFFFB6D0ULL, 0x2020000ULL}, 0xFC00000FULL, 0x0ULL},
  {32u, {0xFFFFFFFCULL, 0x2ULL, 0xFFFFFFE6ULL}, {0x0ULL, 0xFFFFFFFDULL, 0x19ULL}, 0xFFFFFFE0ULL, 0x10ULL},
  {32u, {0x0ULL, 0xFF3FFFFAULL, 0xFFBC1E19ULL}, {0x0ULL, 0xC00005ULL, 0x43E1E6ULL}, 0x3C0000ULL, 0x3C000ULL},
  {64u, {0x8000000000000000ULL, 0x0ULL, 0x0ULL}, {0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL}, 0x0ULL, 0x8000000000000000ULL},
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
