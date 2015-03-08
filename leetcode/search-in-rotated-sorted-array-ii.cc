class Solution {
public:
  bool search(int A[], int n, int target) {
    // These are wrong answers
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (A[mid] == target)
        return true;
      if (A[mid] > A[low])
      {
        if (A[mid] <= target || target >= A[low])
          low = mid;
        else
          high = mid;
      }
      else
      {
        if (A[mid] >= target || target <= A[high])
          high = mid;
        else
          low = mid;
      }
    }

    return false;
  }
};
