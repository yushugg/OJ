#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

struct Result
{
  int rank;
  int total;
  int scores[5];  // -2 for never submit, -1 for compil failed
  int perfectNum;
};

std::map<int, Result> resultMap;
std::vector<std::pair<int, Result> > resultVec;

bool cmp(std::pair<int, Result> res1, std::pair<int, Result> res2)
{
  if (res1.second.total == res2.second.total)
  {
    if (res1.second.perfectNum == res2.second.perfectNum)
      return res1.first < res2.first;
    else
      return res1.second.perfectNum > res2.second.perfectNum;
  }
  else
    return res1.second.total > res2.second.total;
}

int main()
{
  freopen("in.txt", "r", stdin);
  // Read data
  int userNum, proNum, submitNum;
  scanf("%d%d%d", &userNum, &proNum, &submitNum);
  int* proScores = new int[proNum];
  for (int i = 0; i < proNum; ++i)
    scanf("%d", &proScores[i]);

  for (int i = 0; i < submitNum; ++i)
  {
    int id;
    int proId, score;
    scanf("%d%d%d", &id, &proId, &score);
    if (resultMap.find(id) == resultMap.end())
    {
      Result res;
      res.rank = 1;
      res.total = 0;
      for (int j = 0; j < 5; ++j)
        res.scores[j] = -2;
      res.perfectNum = 0;

      resultMap.insert(std::make_pair(id, res));
    }

    // Update result scores array
    if (score > resultMap[id].scores[proId-1])
    {
      resultMap[id].scores[proId-1] = score;
    }
  }

  // Update result total and perfect nums
  for (std::map<int, Result>::iterator iter = resultMap.begin(); iter != resultMap.end(); ++iter)
  {
    for (int i = 0; i < 5; ++i)
    {
      if ((iter->second).scores[i] > 0)
        (iter->second).total += (iter->second).scores[i];
      if ((iter->second).scores[i] == proScores[i])
        ++(iter->second).perfectNum;
    }

    // Add to result vector
    resultVec.push_back(*iter);

    // Test
    /*printf("%05d %d", iter->first, (iter->second).total);
    for (int i = 0; i < 5; ++i)
      printf(" %d", (iter->second).scores[i]);
    putchar('\n');*/
  }

  // Sorting
  std::sort(resultVec.begin(), resultVec.end(), cmp);

  // Print
  //puts("After sorting");
  int ranks = 1;
  int preScore = -1;
  int preRank = 0;
  for (std::vector<std::pair<int, Result> >::iterator iter = resultVec.begin(); iter != resultVec.end(); ++iter)
  {
    bool p = true;
    for (int i = 0; i < proNum; ++i)
    {
      if ((iter->second).scores[i] >= 0)
      {
        p = false;
        break;
      }
    }
    if (p)
      continue;
    if ((iter->second).total == preScore)
      (iter->second).rank = preRank;
    else
      (iter->second).rank = ranks;
    ++ranks;
    preRank = (iter->second).rank;
    preScore = (iter->second).total;
    printf("%d %05d %d", (iter->second).rank, iter->first, (iter->second).total);
    for (int i = 0; i < proNum; ++i)
    {
      if ((iter->second).scores[i] >= 0)
        printf(" %d", (iter->second).scores[i]);
      else if ((iter->second).scores[i] == -1)
        printf(" 0");
      else
        printf(" -");
    }
    putchar('\n');
  }

  delete[] proScores;

  return 0;
}

