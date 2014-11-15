#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

int main()
{
  freopen("in.txt", "r", stdin);

  int N, K;
  scanf("%d%d", &N, &K);
  std::vector<char*> nameList[2500];

  for (int i = 0; i < N; ++i)
  {
    char* name = new char[5];
    int numOfCourses;
    scanf("%s%d", name, &numOfCourses);

    for (int j = 0; j < numOfCourses; ++j)
    {
      int course;
      scanf("%d", &course);
      nameList[course - 1].push_back(name);
    }
  }

  for (int i = 0; i < K; ++i)
  {
    std::sort(nameList[i].begin(), nameList[i].end(), [](const char* name1, const char* name2) -> bool{
      return strcmp(name1, name2) < 0;
    });

    printf("%d %lu\n", i+1, nameList[i].size());
    for (auto iter = nameList[i].begin(); iter != nameList[i].end(); ++iter)
    {
      printf("%s\n", *iter);
    }
  }

  return 0;
}

