namespace Sub_arg0_Sub_arg1_arg0 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[2], argO[2], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0x61C88635ULL}, {0x0ULL, 0x9E3779CAULL}, 0x1ULL, 0x0ULL},
  {32u, {0x0ULL, 0x61C88646ULL}, {0x0ULL, 0x9E3779B9ULL}, 0x0ULL, 0x1ULL},
  {32u, {0x0ULL, 0x61C88638ULL}, {0x0ULL, 0x9E3779C7ULL}, 0x0ULL, 0x1ULL},
};
} // namespace

std::array<APInt, 2> solution(unsigned bw, std::array<APInt, 2> ssa_0, std::array<APInt, 2> ssa_1) {
  unsigned opbw = ssa_0[0].getBitWidth();
  if (ssa_0[0].getBitWidth() > 64 || ssa_1[0].getBitWidth() > 64) return std::array<APInt, 2>{APInt(bw, 0), APInt(bw, 0)};
  uint64_t inZ[2], inO[2];
  inZ[0] = ssa_0[0].getZExtValue();
  inO[0] = ssa_0[1].getZExtValue();
  inZ[1] = ssa_1[0].getZExtValue();
  inO[1] = ssa_1[1].getZExtValue();
  uint64_t outZ = 0, outO = 0;
  for (const Entry &E : kEntries) {
    if (E.bw != opbw) continue;
    bool match = true;
    for (unsigned a = 0; a < 2; ++a)
      if ((E.argZ[a] & ~inZ[a]) | (E.argO[a] & ~inO[a])) { match = false; break; }
    if (match) outZ |= E.outZ, outO |= E.outO;
  }
  return std::array<APInt, 2>{APInt(bw, outZ), APInt(bw, outO)};
}
}
