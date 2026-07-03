namespace Sub_arg0_Mul_Udiv_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFD8EFULL, 0xFFFFD8EFULL}, {0x0ULL, 0x2710ULL, 0x2710ULL}, 0xFFFFC000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFA4AULL, 0xFFFFFA4AULL}, {0x0ULL, 0x5B5ULL, 0x5B5ULL}, 0xFFFFF800ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFE6ULL, 0xFFFFFFE6ULL}, {0x0ULL, 0x19ULL, 0x19ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFDC54EULL, 0xFFFDC54EULL}, {0x0ULL, 0x23AB1ULL, 0x23AB1ULL}, 0xFFFC0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFDFULL, 0xFFFFFFDFULL}, {0x0ULL, 0x20ULL, 0x20ULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFBFFULL, 0xFFFFFFFFFFFFFBFFULL}, {0x0ULL, 0x400ULL, 0x400ULL}, 0xFFFFFFFFFFFFFC00ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFDFULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x20ULL, 0x20ULL}, 0xFFFFFFFFFFFFFFE0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFDBFULL, 0xFFFFFFFFFFFFFDBFULL}, {0x0ULL, 0x240ULL, 0x240ULL}, 0xFFFFFFFFFFFFFC00ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFBFULL, 0xFFFFFFFFFFFFFFBFULL}, {0x0ULL, 0x40ULL, 0x40ULL}, 0xFFFFFFFFFFFFFFC0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFF7ULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x8ULL, 0x8ULL}, 0xFFFFFFFFFFFFFFF8ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFF7FFULL, 0xFFFFFFFFFFFFF7FFULL}, {0x0ULL, 0x800ULL, 0x800ULL}, 0xFFFFFFFFFFFFF800ULL, 0x0ULL},
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
