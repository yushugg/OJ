#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  void permute(vector<vector<int> > &result, vector<int> permutation, vector<bool>& visited, vector<int> &num) {
    if (permutation.size() == num.size()) { result.push_back(permutation); return ; }
    bool prevBool = true; int prev;
    for (int i = 0; i < num.size(); ++i) {
      if (!visited[i] && (prevBool || prev != num[i])) {
        prevBool = false;
        prev = num[i];
        permutation.push_back(num[i]);
        visited[i] = true;
        permute(result, permutation, visited, num);
        visited[i] = false;
        permutation.pop_back();
      }
    }
  }

  vector<vector<int> > permuteUnique(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> > result;
    vector<int> permutation;
    vector<bool> visited(num.size(), false);
    permute(result, permutation, visited, num);

    return result;
  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> num;
  for (int i = 0; i < size; ++i) { int temp; scanf("%d", &temp); num.push_back(temp); }

  Solution solution;
  vector<vector<int> > result = solution.permuteUnique(num);

  for (auto iter = result.begin(); iter != result.end(); ++iter) {
    for (auto it = iter->begin(); it != iter->end(); ++it) {
      printf("%d,", *it);
    }
    puts("");
  }

  return 0;
}
