#include <cstdio>
#include <vector>
#include <algorithm>

struct Record
{
  int ge;
  int gi;
  int id;
  int choice[5];
  int rank;
  int rankCnt;
};

struct ScoreLine
{
  int ge;
  int gi;
  int gt;
};

std::vector<Record> recVec;
std::vector<int> result[100];
ScoreLine sl[100];
int quota[100];

bool cmp(Record r1, Record r2)
{
  if ((r1.ge + r1.gi) > (r2.ge + r2.gi))
    return true;
  else if ((r1.ge + r1.gi) < (r2.ge + r2.gi))
    return false;
  else
  {
    return r1.ge > r2.ge;
  }
}

int main()
{
  freopen("in.txt", "r", stdin);
  int appNum, schNum, choiceNum;
  scanf("%d%d%d", &appNum, &schNum, &choiceNum);

  for (int i = 0; i < schNum; ++i)
    scanf("%d", &quota[i]);

  for (int i = 0; i < appNum; ++i)
  {
    Record temp;
    scanf("%d%d", &temp.ge, &temp.gi);
    for (int j = 0; j < choiceNum; ++j)
      scanf("%d", &temp.choice[j]);
    temp.id = i;
    temp.rank = 0;
    temp.rankCnt = 0;

    recVec.push_back(temp);
  }

  // Sort
  std::sort(recVec.begin(), recVec.end(), cmp);
  recVec[0].rank = 0;
  for (int i = 1; i < appNum; ++i)
  {
    if ((recVec[i].ge + recVec[i].gi) == (recVec[i-1].ge + recVec[i-1].gi) && recVec[i].ge == recVec[i-1].ge)
      recVec[i].rank = recVec[i-1].rank;
    else
      recVec[i].rank = i;
  }

  // Admission
  for (int i = 0; i < appNum; ++i)
  {
    for (int j = 0; j < choiceNum; ++j)
    {
      if (quota[recVec[i].choice[j]])
      {
        result[recVec[i].choice[j]].push_back(recVec[i].id);
        --quota[recVec[i].choice[j]];
        sl[recVec[i].choice[j]].ge = recVec[i].ge;
        sl[recVec[i].choice[j]].gi = recVec[i].gi;
        sl[recVec[i].choice[j]].gt = recVec[i].ge + recVec[i].gi;
        break;
      }
      else
      {
        // Same score
        if (recVec[i].ge == sl[recVec[i].choice[j]].ge && recVec[i].gi == sl[recVec[i].choice[j]].gi)
        {
          result[recVec[i].choice[j]].push_back(recVec[i].id);
          break;
        }
      }
    }
  }

  // Test output
  /*for (int i = 0; i < appNum; ++i)
  {
    printf("%d %d %d %d", recVec[i].rank, recVec[i].id, recVec[i].ge, recVec[i].gi);
    for (int j = 0; j < choiceNum; ++j)
      printf(" %d", recVec[i].choice[j]);
    putchar('\n');
  }*/

  for (int i = 0; i < schNum; ++i)
  {
    if (result[i].empty())
    {
      putchar('\n');
      continue;
    }
    std::sort(result[i].begin(), result[i].end());
    for (size_t j = 0; j < result[i].size()-1; ++j)
      printf("%d ", result[i][j]);
    printf("%d\n", result[i][result[i].size()-1]);
  }

  return 0;
}

