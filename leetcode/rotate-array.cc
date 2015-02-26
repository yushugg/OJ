#include <cstdio>

class Solution {
public:
  void reverseArray(int nums[], int n) {
    for (int i = 0; i < n / 2; ++i)
    {
      int temp = nums[i];
      nums[i] = nums[n - i - 1];
      nums[n - i - 1] = temp;
    }
  }
  void rotate(int nums[], int n, int k) {
    k = k % n;
    reverseArray(nums, n - k);
    reverseArray(nums + n - k, k);
    reverseArray(nums, n);
  }
};

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  int* nums = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &nums[i]);

  int k;
  scanf("%d", &k);

  // Rotate
  Solution s;
  s.rotate(nums, n, k);

  // Output result
  for (int i = 0; i < n - 1; ++i)
    printf("%d ", nums[i]);
  printf("%d\n", nums[n - 1]);

  delete[] nums;

  return 0;
}

