namespace AddNsw_Mul_arg0_arg1_arg2 {
namespace {
struct Entry { unsigned bw; uint64_t argZ[3], argO[3], outZ, outO; };
static constexpr Entry kEntries[] = {
  {8u, {0xC0ULL, 0xF5ULL, 0xDFULL}, {0x30ULL, 0xAULL, 0x20ULL}, 0x81ULL, 0x0ULL},
  {8u, {0xC0ULL, 0xF5ULL, 0xD0ULL}, {0x30ULL, 0xAULL, 0x20ULL}, 0x80ULL, 0x0ULL},
  {8u, {0xC0ULL, 0xF5ULL, 0xC0ULL}, {0x30ULL, 0xAULL, 0x30ULL}, 0x80ULL, 0x0ULL},
  {32u, {0xBDA597C0ULL, 0xFFFE795FULL, 0x333A3DFFULL}, {0x425A6830ULL, 0x186A0ULL, 0xCCC5C200ULL}, 0xFFE0001FULL, 0x0ULL},
  {64u, {0xFFFFFFFFFFFFFF80ULL, 0x1100AFB8A63E94B7ULL, 0x4089B058A25136EAULL}, {0x0ULL, 0xEEFF504759C16B48ULL, 0xBF764FA75DAEC915ULL}, 0x80000000000002ULL, 0x5ULL},
  {64u, {0xFFFFFFFFFFFFFFC8ULL, 0x1100AFB8A63E94B7ULL, 0x4089B058A25136EAULL}, {0x0ULL, 0xEEFF504759C16B48ULL, 0xBF764FA75DAEC915ULL}, 0x4080000000000002ULL, 0x840000000000005ULL},
  {64u, {0xFFFFFFFFFFFFFFC8ULL, 0x1100AFB8A63E94B7ULL, 0x4089B058A25136EAULL}, {0x34ULL, 0xEEFF504759C16B48ULL, 0xBF764FA75DAEC915ULL}, 0xC4AE010001000002ULL, 0x8500E2000384005ULL},
  {64u, {0xFFFFFFFFFFFFFFFEULL, 0xFFFFFFFFFFFFFFF3ULL, 0xBULL}, {0x0ULL, 0xCULL, 0xFFFFFFFFFFFFFFF4ULL}, 0xBULL, 0x0ULL},
  {64u, {0xFFFFFFFF00000000ULL, 0xFFFFFFFFFFFFFFF5ULL, 0xFFFFFFFFFFFFFFF0ULL}, {0x0ULL, 0xAULL, 0x0ULL}, 0xFFFFFFF000000000ULL, 0x0ULL},
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
