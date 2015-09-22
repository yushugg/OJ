#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {

  }
};

int main() {
  int size;
  scanf("%d", &size);
  vector<int> citations;
  while (size--) {
    int val;
    scanf("%d", &val);
    citations.push_back(val);
  }

  Solution solution;
  printf("%d\n", solution.hIndex(citations));

  return 0;
}

