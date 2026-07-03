namespace Sub_arg0_Umin_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {64u, {0xFFFFFFFFFFFFFFF2ULL, 0xFFFFFFFFFFFFFFF2ULL, 0x0ULL}, {0xDULL, 0xDULL, 0x0ULL}, 0xFFFFFFFFFFFFFFF0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFBFULL, 0xFFFFFFFFFFFFFFBFULL, 0x0ULL}, {0x40ULL, 0x40ULL, 0x0ULL}, 0xFFFFFFFFFFFFFF80ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFEBULL, 0xFFFFFFFFFFFFFFEBULL, 0x0ULL}, {0x14ULL, 0x14ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFFFFDFULL, 0x0ULL}, {0x20ULL, 0x20ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFFAULL, 0xFFFFFFFFFFFFFFFAULL, 0x0ULL}, {0x5ULL, 0x5ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFFD6ULL, 0xFFFFFFFFFFFFFFD7ULL, 0x0ULL}, {0x29ULL, 0x28ULL, 0x0ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFEBBULL, 0xFFFFFFFFFFFFFEBCULL, 0x0ULL}, {0x144ULL, 0x143ULL, 0x0ULL}, 0xFFFFFFFFFFFFFE00ULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFE0000ULL, 0x0ULL, 0xFFFFFFFFFFFEFFFFULL}, {0x10000ULL, 0x0ULL, 0x10000ULL}, 0xFFFFFFFFFFFE0000ULL, 0x0ULL},
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
