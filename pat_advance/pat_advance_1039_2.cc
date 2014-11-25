#include <cstdio>

bool stuCourseList[175760][2500];

int name2Int(char name[])
{
  return (name[0] - 'A') + 
    (name[1] - 'A') * 26 +
    (name[2] - 'A') * 26 * 26 + 
    (name[3] - '0') * 26 * 26 * 26;
}

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
      stuCourseList[name2Int(name)][course - 1] = true;
    }
  }

  for (int i = 0; i < N; ++i)
  {
    char* name = new char[5];
    scanf("%s", name);

    int count = 0;
    for (int j = 0; j < 2500; ++j)
    {
      if (stuCourseList[name2Int(name)][j])
        ++count;
    }

    printf("%s %d", name, count);
    for (int j = 0; j < 2500; ++j)
    {
      if (stuCourseList[name2Int(name)][j])
        printf(" %d", j + 1);
    }
    putchar('\n');
  }

  return 0;
}

