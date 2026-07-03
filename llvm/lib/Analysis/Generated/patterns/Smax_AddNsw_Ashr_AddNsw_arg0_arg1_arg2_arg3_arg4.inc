namespace Smax_AddNsw_Ashr_AddNsw_arg0_arg1_arg2_arg3_arg4 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[5], argO[5], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0x0ULL, 0xFFFFFFF9ULL, 0xFFFF0000ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x6ULL, 0x0ULL, 0x0ULL}, 0xFC000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFCULL, 0xFFFF0000ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x3ULL, 0x3ULL, 0x0ULL, 0x0ULL}, 0xE0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFDFFFULL, 0xFFFFFFF1ULL, 0xFFFF0000ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x2000ULL, 0xEULL, 0x0ULL, 0x0ULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF7F7FULL, 0xFFFFFFEFULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x8080ULL, 0x10ULL, 0x0ULL, 0x0ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0x0ULL, 0xFFFFFFFCULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x0ULL, 0x3ULL, 0x0ULL, 0x0ULL}, 0xE0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFFBULL, 0xFFFF0000ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x8ULL, 0x4ULL, 0x0ULL, 0x0ULL}, 0xF0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEFULL, 0xFFFFFFFAULL, 0xFFFF0000ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x10ULL, 0x5ULL, 0x0ULL, 0x0ULL}, 0xF8000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFDFULL, 0xFFFFFFF9ULL, 0xF8000000ULL, 0xFFFFFFFFULL}, {0x0ULL, 0x20ULL, 0x6ULL, 0x0ULL, 0x0ULL}, 0xF0000000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFF7FFULL, 0xFFFFFFF3ULL, 0xFFFFFF4BULL, 0xFFFFFFFFULL}, {0x0ULL, 0x800ULL, 0xCULL, 0x0ULL, 0x0ULL}, 0xFFF00000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xDULL, 0xFFFFFFFEULL, 0xFFFFFFF0ULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFFFFFF2ULL, 0x1ULL, 0x0ULL, 0x0ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x77ULL, 0xFFFFFFFBULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFFFFF88ULL, 0x4ULL, 0x0ULL, 0x0ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0x77ULL, 0xFFFFFFFBULL, 0xFFFFFF00ULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFFFFF88ULL, 0x4ULL, 0x0ULL, 0x0ULL}, 0xF0000000ULL, 0x0ULL},
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
