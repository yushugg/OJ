#include <cstdio>
#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &num) {
    int appearTimes = 1;
    int major = num[0];
    for (size_t i = 1; i != num.size(); ++i)
    {
      if (num[i] != major)
      {
        --appearTimes;
        if (appearTimes < 1)
        {
          major = num[i];
          appearTimes = 1;
        }
      }
      else
        ++appearTimes;
    }

    return major;
  }
};

int main(int argc, char* argv[])
{
  int a[] = {2, 1, 1, 1, 1, 4};
  std::vector<int> b(a, a + 6);

  Solution s;
  printf("%d\n", s.majorityElement(b));

  return 0;
}

