#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> order;
    vector<int> *siblings = new vector<int>[numCourses];
    int *indegree = new int[numCourses];
    memset(indegree, 0, numCourses * sizeof(int));
    for (auto pre : prerequisites) {
      siblings[pre.second].push_back(pre.first);
      ++indegree[pre.first];
    }

    // Toplogical sort
    while (true) {
      bool loop = true, finished = true;
      // All visited, then break
      for (int i = 0; i < numCourses; ++i) if (indegree[i] != -1) { finished = false; break; }
      if (finished) break;
      // Find course whose indegree = 0
      int idx;
      for (idx = 0; idx < numCourses; ++idx) {
        if (indegree[idx] == 0) { loop = false; break; }
      }
      if (loop) { order.clear(); return order; }

      // decrease indegree
      indegree[idx] = -1;
      order.push_back(idx);
      for (auto sib : siblings[idx]) {
        if (indegree[sib] >= 0) --indegree[sib];
      }
    }

    delete[] siblings;
    delete[] indegree;

    return order;
  }
};

int main() {
  int numCourses;
  scanf("%d", &numCourses);
  int length;
  scanf("%d", &length);
  vector<pair<int, int>> prerequisites;
  for (int i = 0; i < length; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    prerequisites.push_back(make_pair(a, b));
  }

  Solution solution;
  vector<int> order = solution.findOrder(numCourses, prerequisites);

  for (int o : order) printf("%d->", o);
  puts("");

  return 0;
}

