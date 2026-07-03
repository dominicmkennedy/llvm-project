namespace Smax_Sdiv_AddNsw_arg0_arg1_arg2_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {16u, {0xFF00ULL, 0x1ULL, 0xFFFDULL, 0xFFFEULL}, {0x0ULL, 0xFFFEULL, 0x2ULL, 0x1ULL}, 0xFF80ULL, 0x0ULL},
  {16u, {0xFF00ULL, 0x5ULL, 0xFFFBULL, 0xFFFEULL}, {0x0ULL, 0xFFFAULL, 0x4ULL, 0x1ULL}, 0xFFC0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE0ULL, 0xFFFFFFDFULL, 0xFFFFFFFEULL}, {0x0ULL, 0x1FULL, 0x20ULL, 0x1ULL}, 0xFC000000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x5ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFAULL, 0x2ULL, 0x1ULL}, 0xFFFF8000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xBULL, 0xFFFFFFFBULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFF4ULL, 0x4ULL, 0x1ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x1ULL, 0xFFFFFFFDULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFEULL, 0x2ULL, 0x1ULL}, 0xFFFF8000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x3ULL, 0xFFFFFFFBULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFCULL, 0x4ULL, 0x1ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF0ULL, 0xFFFFFFDFULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFULL, 0x20ULL, 0x1ULL}, 0xFC000000ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0xCULL, 0xFFFFFFFCULL, 0xFFFFFFFFULL}, {0x0ULL, 0xFFFFFFF3ULL, 0x3ULL, 0x0ULL}, 0xFFFFFF80ULL, 0x0ULL},
  {32u, {0xFFFFFF00ULL, 0x7ULL, 0xFFFFFFFBULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFF8ULL, 0x4ULL, 0x1ULL}, 0xFFFFFFC0ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0xBULL, 0xFFFFFFF3ULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFF4ULL, 0xCULL, 0x1ULL}, 0xFFFFE000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x7ULL, 0xFFFFFFFBULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFF8ULL, 0x4ULL, 0x1ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x3ULL, 0xFFFFFFEFULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFCULL, 0x10ULL, 0x1ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x3ULL, 0xFFFFFFEBULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFCULL, 0x14ULL, 0x1ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0xFFFF0000ULL, 0x3ULL, 0xFFFFFFDBULL, 0xFFFFFFFEULL}, {0x0ULL, 0xFFFFFFFCULL, 0x24ULL, 0x1ULL}, 0xFFFFF800ULL, 0x0ULL},
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
