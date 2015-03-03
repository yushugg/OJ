class Solution {
public:
  int findMin(std::vector<int> &num) {
    int low = 0, high = num.size() - 1;
    int mid;
    while (num[low] > num[high])
    {
      mid = (low + high) / 2;
      if (num[mid] >= num[low])
        low = mid + 1;
      else if (num[mid] < num[high])
        high = mid;
    }

    return num[low];
  }
};
