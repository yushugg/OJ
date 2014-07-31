#include <cstdio>
#include <list>

struct Supplier
{
  std::list<int> members;
  bool retailer;
  double price;
};

void iterSup(Supplier sups[], const int index, const double rate, double* sum)
{
  if (sups[index].retailer)
  {
    *sum += sups[index].price * sups[index].members.front();
  }
  else
  {
    for (std::list<int>::iterator iter = sups[index].members.begin(); iter != sups[index].members.end(); ++iter)
    {
      sups[*iter].price = sups[index].price * (1 + rate/100);
      iterSup(sups, *iter, rate, sum);
    }
  }
}

int main()
{
  freopen("in.txt", "r", stdin);
  int N;
  double price, r;
  scanf("%d%lf%lf", &N, &price, &r);
  Supplier* sups = new Supplier[N];

  for (int i = 0; i < N; ++i)
  {
    int num;
    scanf("%d", &num);
    if (num)
    {
      sups[i].retailer = false;
      sups[i].price = 0;
      for (int j = 0; j < num; ++j)
      {
        int mem;
        scanf("%d", &mem);
        sups[i].members.push_back(mem);
      }
    }
    else
    {
      int total;
      scanf("%d", &total);
      sups[i].members.push_back(total);
      sups[i].retailer = true;
      sups[i].price = 0;
    }
  }

  // Iterate
  sups[0].price = price;
  double sum = 0;
  iterSup(sups, 0, r, &sum);
  printf("%.1lf\n", sum);
  
  delete[] sups;

  return 0;
}

