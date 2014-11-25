#include <cstdio>
#include <bitset>
#include <map>
#include <cstring>

struct cmp_str
{
  bool operator()(const char* str1, const char* str2) const
  {
    return strcmp(str1, str2) < 0;
  }
};

std::map<char*, std::bitset<2500>, cmp_str> stuCoursesMap;

int main()
{
  freopen("in.txt", "r", stdin);

  int N, K;
  scanf("%d%d", &N, &K);

  for (int i = 0; i < K; ++i)
  {
    int course, numOfStu;
    scanf("%d%d", &course, &numOfStu);
    for (int j = 0; j < numOfStu; ++j)
    {
      char* name = new char[5];
      scanf("%s", name);
      stuCoursesMap[name][course - 1] = 1;
    }
  }

  for (int i = 0; i < N; ++i)
  {
    char* name = new char[5];
    scanf("%s", name);
    printf("%s %d", name, stuCoursesMap[name].count());

    for (int j = 0; j < 2500; ++j)
    {
      if (stuCoursesMap[name].test(j))
        printf(" %d", j + 1);
    }

    putchar('\n');
  }

  return 0;
}

