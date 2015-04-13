#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_map<int, bool> map;
    for (auto iter = num.begin(); iter != num.end(); ++iter) if (map.find(*iter) == map.end()) map.insert(make_pair(*iter, false));

    int max = 0;
    for (auto iter = map.begin(); iter != map.end(); ++iter) {
      if (!iter->second) {
        int l = iter->first, h = iter->first;
        while (map.find(l) != map.end()) map[l--] = true;
        while (map.find(h) != map.end()) map[h++] = true;
        if (max < h - l - 1) max = h - l - 1;
      }
    }

    return max;
  }
};

int main()
{
  int size;
  scanf("%d", &size);
  vector<int> num;
  for (int i = 0; i < size; ++i) { int temp; scanf("%d", &temp); num.push_back(temp); }

  Solution s;
  printf("%d\n", s.longestConsecutive(num));

  return 0;
}

