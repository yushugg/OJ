class Solution {
public:
  int singleNumber(int A[], int n) {
    // ones: each bit of int whether appears once or not
    // twos: each bit of int whether appears twice or not
    // threes: each bit of int whether appears three times or not
    int ones = 0, twos = 0, threes = 0;

    for (int i = 0; i < n; ++i)
    {
      twos |= ones & A[i];
      ones ^= A[i];
      threes = ones & twos;
      ones &= ~threes;
      twos &= ~threes;
    }

    return ones;
  }
};
