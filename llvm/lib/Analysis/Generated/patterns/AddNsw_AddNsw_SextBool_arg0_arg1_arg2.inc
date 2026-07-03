namespace AddNsw_AddNsw_SextBool_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFFFF000ULL, 0xFFFFFFC7ULL}, {0x0ULL, 0x0ULL, 0x38ULL}, 0xFFFFE000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF0000ULL, 0xFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x1ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF8000ULL, 0xFFFF018EULL}, {0x0ULL, 0x0ULL, 0xFE71ULL}, 0xFFFE0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFEEULL, 0x0ULL}, {0x0ULL, 0x10ULL, 0xFFFFFFFFULL}, 0xFFFFFFE0ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFF8000ULL, 0xFFFFFF07ULL}, {0x0ULL, 0x0ULL, 0xF8ULL}, 0xFFFF0000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFF800ULL, 0xFFFFFFC7ULL}, {0x0ULL, 0x0ULL, 0x38ULL}, 0xFFFFF000ULL, 0x0ULL},
  {32u, {0x0ULL, 0xFFFFFFF2ULL, 0x0ULL}, {0x0ULL, 0xCULL, 0xFFFFFFFFULL}, 0xFFFFFFF0ULL, 0x8ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFC000000ULL, 0xFFFFFFFF00000001ULL}, {0x0ULL, 0x0ULL, 0xFFFFFFFEULL}, 0xFFFFFFFE00000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFC000000ULL, 0xFFFFFFFFFFFFFFFEULL}, {0x0ULL, 0x0ULL, 0x1ULL}, 0xFFFFFFFFF8000000ULL, 0x0ULL},
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
