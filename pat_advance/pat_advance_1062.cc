#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>


struct Grade
{
  char id[9];
  int virtue;
  int talent;
};

bool cmp(Grade g1, Grade g2)
{
  if (g1.virtue + g1.talent != g2.virtue + g2.talent)
    return g1.virtue + g1.talent > g2.virtue + g2.talent;
  else
  {
    if (g1.virtue != g2.virtue)
      return g1.virtue > g2.virtue;
    else
      return strcmp(g1.id, g2.id) < 0;
  }
}

void printVector(std::vector<Grade> vec)
{
  for (std::vector<Grade>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    printf("%s %d %d\n", iter->id, iter->virtue, iter->talent);
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N, L, H;
  scanf("%d%d%d", &N, &L, &H);

  std::vector<Grade> sages;
  std::vector<Grade> nobleMen;
  std::vector<Grade> foolMen;
  std::vector<Grade> others;
  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    Grade g;
    scanf("%s%d%d", g.id, &g.virtue, &g.talent);
    if (g.virtue >= L && g.talent >= L)
    {
      ++count;
      if (g.virtue >= H && g.talent >= H)
        sages.push_back(g);
      else if (g.talent < H && g.virtue >= H)
        nobleMen.push_back(g);
      else if (g.talent < H && g.virtue < H && g.virtue >= g.talent)
        foolMen.push_back(g);
      else
        others.push_back(g);
    }
  }
  printf("%d\n", count);

  // Sort
  std::sort(sages.begin(), sages.end(), cmp);
  std::sort(nobleMen.begin(), nobleMen.end(), cmp);
  std::sort(foolMen.begin(), foolMen.end(), cmp);
  std::sort(others.begin(), others.end(), cmp);

  printVector(sages);
  printVector(nobleMen);
  printVector(foolMen);
  printVector(others);

  return 0;
}

