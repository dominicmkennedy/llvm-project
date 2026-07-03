namespace AddNsw_MulNsw_Udiv_arg0_arg1_arg2_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFDC54EULL, 0x23AB0ULL}, {0x0ULL, 0x23AB1ULL, 0xFFFDC54FULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0x80000000ULL, 0xFFF0BDBFULL, 0xF423FULL}, {0x0ULL, 0xF4240ULL, 0xFFF0BDC0ULL}, 0xFFF00000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFEAE7FULL, 0x1517FULL}, {0x0ULL, 0x15180ULL, 0xFFFEAE80ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFD8EFULL, 0x270FULL}, {0x0ULL, 0x2710ULL, 0xFFFFD8F0ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xFFFFFCD5ULL, 0x329ULL}, {0x0ULL, 0x32AULL, 0xFFFFFCD6ULL}, 0xFFFFFC00ULL, 0x0ULL},
  {32u, {0xFFFFFC00ULL, 0xFFFFFFF9ULL, 0x5ULL}, {0x0ULL, 0x6ULL, 0xFFFFFFFAULL}, 0xFFFFFFF8ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xFFFFFFF6ULL, 0x8ULL}, {0x0ULL, 0x9ULL, 0xFFFFFFF7ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFF800ULL, 0xFFFFFFA1ULL, 0x5DULL}, {0x0ULL, 0x5EULL, 0xFFFFFFA2ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {64u, {0xFFFFFFE000000000ULL, 0xFFFFFFFF296C5BFFULL, 0xD693A3FFULL}, {0x0ULL, 0xD693A400ULL, 0xFFFFFFFF296C5C00ULL}, 0xFFFFFFFF00000000ULL, 0x0ULL},
  {64u, {0xFFFF800000000000ULL, 0xFFFFFCB9CF475FFFULL, 0x34630B89FFFULL}, {0x0ULL, 0x34630B8A000ULL, 0xFFFFFCB9CF476000ULL}, 0xFFFFFC0000000000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFF8000000ULL, 0xFFFFFFFFFFFEAE7FULL, 0x1517FULL}, {0x0ULL, 0x15180ULL, 0xFFFFFFFFFFFEAE80ULL}, 0xFFFFFFFFFFFE0000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFF80000ULL, 0xFFFFFFFFFFFFF1EFULL, 0xE0FULL}, {0x0ULL, 0xE10ULL, 0xFFFFFFFFFFFFF1F0ULL}, 0xFFFFFFFFFFFFF000ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF00ULL, 0xFFFFFFFFFFFFFFF5ULL, 0x9ULL}, {0x0ULL, 0xAULL, 0xFFFFFFFFFFFFFFF6ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFF0BDBFULL, 0xF423FULL}, {0x0ULL, 0xF4240ULL, 0xFFFFFFFFFFF0BDC0ULL}, 0xFFFFFFFFFFF00000ULL, 0x0ULL},
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
