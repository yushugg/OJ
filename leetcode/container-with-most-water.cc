class Solution {
public:
  int maxArea(vector<int> &height) {
    int low = 0;
    int high = height.size() - 1;

    int max = 0;
    while (low < high)
    {
      int h = height[low] > height[high] ? height[high] : height[low];
      int area = h * (high - low);

      if (max < area)
        max = area;

      if (height[low] < height[high])
        ++low;
      else
        --high;
    }

    return max;
  }
};
