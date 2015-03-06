class Solution {
public:
  void sortColors(int A[], int n) {
    int red, white, blue;
    red = white = blue = 0;

    for (int i = 0; i < n; ++i)
    {
      if (A[i] == 0)
        ++red;
      else if (A[i] == 1)
        ++white;
      else
        ++blue;
    }

    for (int i = 0; i < n; ++i)
    {
      if (i < red)
        A[i] = 0;
      else if (i >= red && i < red + white)
        A[i] = 1;
      else
        A[i] = 2;
    }
  }
  void sortColorsOneIteration(int A[], int n) {
    // start for 0, end for 2
    int start = 0;
    int end = n - 1;
    int i = 0;

    while (i <= end) {
      if (A[i] == 0)
        std::swap(A[start++], A[i++]);
      else if (A[i] == 2)
        std::swap(A[end--], A[i]);
      else
        ++i;
    }
  }
};
