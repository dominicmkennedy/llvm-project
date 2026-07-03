namespace Add_Umin_Add_Umin_arg0_arg1_arg2_arg0_arg3 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[4], argO[4], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFEFULL, 0xFFFFFFEFULL}, {0x8ULL, 0x0ULL, 0x10ULL, 0x10ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF6ULL, 0xFFFFFFFEULL, 0xFFFFFFFEULL}, {0x0ULL, 0x9ULL, 0x1ULL, 0x1ULL}, 0xFFFFFFF0ULL, 0x0ULL},
  {32u, {0xFFFFFF07ULL, 0x0ULL, 0xFFFFFFFDULL, 0xFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0x2ULL, 0x3ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFF07ULL, 0x0ULL, 0xFFFFFFF1ULL, 0xFFFFFFFDULL}, {0x0ULL, 0x0ULL, 0xEULL, 0x2ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEEULL, 0xFFFFFFFBULL, 0xFFFFFFFBULL}, {0x0ULL, 0x11ULL, 0x4ULL, 0x4ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x80000007ULL, 0x0ULL, 0xFFFFFFF5ULL, 0xFFFFFFFCULL}, {0x0ULL, 0x0ULL, 0xAULL, 0x3ULL}, 0x80000000ULL, 0x0ULL},
  {32u, {0xFFFFFF57ULL, 0x0ULL, 0xFFFFFFF8ULL, 0xFFFFFFF8ULL}, {0x8ULL, 0x0ULL, 0x7ULL, 0x7ULL}, 0xFFFFFF00ULL, 0x0ULL},
  {32u, {0xFFFFFEE7ULL, 0xFFFFFFEFULL, 0xFFFFFFEFULL, 0xFFFFFFE7ULL}, {0x8ULL, 0x10ULL, 0x10ULL, 0x18ULL}, 0xFFFFFFC7ULL, 0x20ULL},
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFFCULL, 0xFFFFFFFAULL}, {0x8ULL, 0x0ULL, 0x3ULL, 0x5ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFFBULL, 0xFFFFFFEFULL}, {0x8ULL, 0x0ULL, 0x4ULL, 0x10ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFFAULL, 0xFFFFFFFBULL}, {0x8ULL, 0x0ULL, 0x5ULL, 0x4ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFEBULL, 0xFFFFFFFCULL}, {0x8ULL, 0x0ULL, 0x14ULL, 0x3ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFE7ULL, 0xFFFFFFEBULL}, {0x8ULL, 0x0ULL, 0x18ULL, 0x14ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFEE7ULL, 0x0ULL, 0xFFFFFFE7ULL, 0xFFFFFFE7ULL}, {0x8ULL, 0x0ULL, 0x18ULL, 0x18ULL}, 0xFFFFFE00ULL, 0x0ULL},
  {32u, {0xFFFFFF57ULL, 0x0ULL, 0xFFFFFFF7ULL, 0xFFFFFFF8ULL}, {0x8ULL, 0x0ULL, 0x8ULL, 0x7ULL}, 0xFFFFFF00ULL, 0x0ULL},
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
