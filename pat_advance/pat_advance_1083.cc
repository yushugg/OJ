#include <cstdio>
#include <vector>
#include <algorithm>

struct Record
{
  char name[15];
  char id[15];
  int grade;
};

std::vector<Record> reVec;

bool cmp(Record r1, Record r2)
{
  return r1.grade > r2.grade;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; ++i)
  {
    Record temp;
    scanf("%s", temp.name);
    scanf("%s", temp.id);
    scanf("%d", &temp.grade);
    reVec.push_back(temp);
  }
  int g1, g2;
  scanf("%d%d", &g1, &g2);

  std::sort(reVec.begin(), reVec.end(), cmp);
  int count = 0;
  for (std::vector<Record>::iterator iter = reVec.begin(); iter != reVec.end(); ++iter)
  {
    if (iter->grade <= g2 && iter->grade >= g1)
    {
      printf("%s %s\n", iter->name, iter->id);
      ++count;
    }
  }

  if (!count)
    printf("NONE\n");

  return 0;
}

