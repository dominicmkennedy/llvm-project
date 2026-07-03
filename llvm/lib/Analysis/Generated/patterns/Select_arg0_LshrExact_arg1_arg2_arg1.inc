namespace Select_arg0_LshrExact_arg1_arg2_arg1 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {32u, {0x0ULL, 0xFFE00000ULL, 0xFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x10ULL}, 0xFFE0FFE0ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFE0000000000ULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL}, 0xFFFFFE00FFFFFE00ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFF00000000000ULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL}, 0xFFFFF000FFFFF000ULL, 0x0ULL},
  {64u, {0x0ULL, 0x8000000000000000ULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL}, 0x8000000080000000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFF80000000ULL, 0xFFFFFFFFFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x10ULL}, 0xFFFFFFFF80008000ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL}, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFDFF7FFFFFEULL, 0xFFFFFFFFFFFFFFDFULL}, {0x0ULL, 0x0ULL, 0x20ULL}, 0xFFFFFFDFFFFFFFDFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFDFF7FFFFDEULL, 0xFFFFFFFFFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x10ULL}, 0xFFFFFFDFF7DFF7FFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFF7FFFFFEULL, 0xFFFFFFFFFFFFFFEFULL}, {0x0ULL, 0x0ULL, 0x10ULL}, 0xFFFFFFFFF7FFF7FFULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFF80ULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFFFFFFFFF88ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFF7FFF7FEULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFFFF7F7F7F7ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFDFF7DFF7DEULL, 0xFFFFFFFFFFFFFFF7ULL}, {0x0ULL, 0x0ULL, 0x8ULL}, 0xFFFFFFDFD7D7D7F7ULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFFFFFFFDEULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFFFFFFFFFDDULL, 0x0ULL},
  {64u, {0x0ULL, 0xFFFFFFFFF7F7F7F6ULL, 0xFFFFFFFFFFFFFFFBULL}, {0x0ULL, 0x0ULL, 0x4ULL}, 0xFFFFFFFFF777777FULL, 0x0ULL},
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
