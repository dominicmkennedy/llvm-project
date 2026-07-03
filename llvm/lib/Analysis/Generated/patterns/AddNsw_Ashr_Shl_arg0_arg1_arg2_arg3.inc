namespace AddNsw_Ashr_Shl_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0xFFFFFFEFULL, 0xFFFF7FDFULL}, {0x0ULL, 0x10ULL, 0x10ULL, 0x8020ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL, 0xFFFFFFE7ULL, 0xC1C71BULL}, {0x0ULL, 0x18ULL, 0x18ULL, 0xFF3E38E4ULL}, 0xC1C600ULL, 0xFF3E3800ULL},
  {32u, {0x0ULL, 0xFFFFFFE7ULL, 0xFFFFFFE7ULL, 0xC1C71EULL}, {0x0ULL, 0x18ULL, 0x18ULL, 0xFF3E38E1ULL}, 0xC1C600ULL, 0xFF3E3800ULL},
  {32u, {0x0ULL, 0xFFFFFFE4ULL, 0xFFFFFFE0ULL, 0xFFFFFFFDULL}, {0x8ULL, 0x1BULL, 0x1FULL, 0x2ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE2ULL, 0xFFFFFFE0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x1DULL, 0x1FULL, 0x2ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0xFFFFFFE0ULL, 0xFFFFFFF7ULL}, {0x0ULL, 0x10ULL, 0x1FULL, 0x8ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE1ULL, 0xFFFFFFE0ULL, 0xFFFFFFB3ULL}, {0x0ULL, 0x1EULL, 0x1FULL, 0x4CULL}, 0xFFFFFFB0ULL, 0x48ULL},
  {32u, {0xFFFF8000ULL, 0xFFFFFFE7ULL, 0xFFFFFFE0ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x18ULL, 0x1FULL, 0x2ULL}, 0xFFFFFFFCULL, 0x0ULL},
  {64u, {0x7ULL, 0xFFFFFFFFFFFFFFC3ULL, 0xFFFFFFFFFFFFFFC0ULL, 0xFFFFFFFFFFFFFFFDULL}, {0x0ULL, 0x3CULL, 0x3FULL, 0x2ULL}, 0xFFFFFFFFFFFFFFFCULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFFC7ULL, 0xFDDDDDDDDDDDDDDDULL}, {0x0ULL, 0x28ULL, 0x38ULL, 0x222222222222222ULL}, 0xFDDDDDDDDDDDDC00ULL, 0x222222222222000ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFFC7ULL, 0xFFFFFFFFFDDDDDDDULL}, {0x0ULL, 0x28ULL, 0x38ULL, 0x2222222ULL}, 0xFFFFFFFFFDDDDC00ULL, 0x2222000ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFD7ULL, 0xFFFFFFFFFFFFFFC7ULL, 0x2222221ULL}, {0x0ULL, 0x28ULL, 0x38ULL, 0xFFFFFFFFFDDDDDDEULL}, 0x2222000ULL, 0xFFFFFFFFFDDDDC00ULL},
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
