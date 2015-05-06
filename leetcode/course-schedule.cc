#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int indegree[numCourses];
    memset(indegree, 0, numCourses * sizeof(int));
    vector<int> *siblings = new vector<int>[numCourses];
    for (int i = 0; i < prerequisites.size(); ++i) {
      siblings[prerequisites[i][1]].push_back(prerequisites[i][0]);
      ++indegree[prerequisites[i][0]];
    }
    while (true) {
      int min = -1; bool finish = true;
      for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] != -1) finish = false;
        if (indegree[i] == 0) { min = i; break; }
      }
      if (finish) return true;
      if (min == -1) return false;
      indegree[min] = -1;
      for (auto iter = siblings[min].begin(); iter != siblings[min].end(); ++iter) {
        --indegree[*iter];
      }
    }
    return true;
  }
};

int main() {
  int numCourses;
  scanf("%d", &numCourses);
  int size;
  scanf("%d", &size);
  vector<vector<int> > prerequisites;
  for (int i = 0; i < size; ++i) {
    vector<int> pair;
    for (int j = 0; j < 2; ++j) {
      int val;
      scanf("%d", &val);
      pair.push_back(val);
    }
    prerequisites.push_back(pair);
  }

  Solution solution;
  printf("can finish: %d\n", solution.canFinish(numCourses, prerequisites));

  return 0;
}

