#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    std::vector<int> nums(numbers);
    std::sort(nums.begin(), nums.end());

    int low = 0;
    int high = nums.size() - 1;
    std::vector<int> result;
    while (low <= high)
    {
      if (nums[low] + nums[high] == target)
      {
        result.push_back(low + 1);
        result.push_back(high + 1);
        break;
      }
      else if (nums[low] + nums[high] > target)
        --high;
      else
        ++low;
    }

    std::vector<int> realResult;
    for (auto iter = result.begin(); iter != result.end(); ++iter)
    {
      for (auto it = numbers.begin(); it != numbers.end(); ++it)
      {
        if (*it == nums[*iter - 1])
        {
          realResult.push_back(it - numbers.begin() + 1);
          break;
        }
      }
    }

    if (realResult[0] == realResult[1])
    {
      for (int i = numbers.size() - 1; i >= 0; --i)
      {
        if (numbers[i] == nums[realResult[0]])
        {
          realResult[1] = i + 1;
          break;
        }
      }
    }

    std::sort(realResult.begin(), realResult.end());

    return realResult;
  }
};

vector<int> TwoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        if (map.find(target - nums[i]) != map.end()) {
            result.push_back(map[target-nums[i]] + 1);
            result.push_back(i + 1);
            return result;
        } else {
            map.emplace(nums[i], i);
        }
    }
}

int main(int argc, char* argv[])
{
  int size;
  scanf("%d", &size);
  std::vector<int> numbers;
  for (int i = 0; i < size; ++i)
  {
    int temp;
    scanf("%d", &temp);
    numbers.push_back(temp);
  }

  int target;
  scanf("%d", &target);
  
  //Solution s;
  //std::vector<int> result = s.twoSum(numbers, target);
  std::vector<int> result = TwoSum(numbers, target);
  for (auto iter = result.begin(); iter != result.end(); ++iter)
    printf("%d\n", *iter);

  return 0;
}

