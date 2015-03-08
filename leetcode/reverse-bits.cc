class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t maskTop = 0x80000000;
    uint32_t maskEnd = 0x1;
    uint32_t result = 0;
    for (int i = 0; i < 16; ++i)
    {
      uint32_t top = n & maskTop;
      uint32_t end = n & maskEnd;
      top >>= 31 - 2 * i;
      end <<= 31 - 2 * i;
      result |= (top | end);

      maskTop >>= 1;
      maskEnd <<= 1;
    }

    return result;
  }
};
