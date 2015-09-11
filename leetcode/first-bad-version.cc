// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int start = 1, end = n, mid;
    while (start <= end) {
      mid = start + (end - start) / 2;
      if (mid == start) if (isBadVersion(mid)) return mid; else start = mid + 1;
      else {
        if (!isBadVersion(mid - 1) && isBadVersion(mid)) return mid;
        else if (isBadVersion(mid)) end = mid - 1;
        else start = mid + 1;
      }
    }
  }
};
