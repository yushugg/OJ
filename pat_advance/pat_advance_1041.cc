#include <cstdio>

struct Num
{
  int times;
  int index;
};

int main()
{
  int N;
  scanf("%d", &N);

  const int total = 10000;
  Num nums[total];
  for (int i = 0; i < total; ++i)
  {
    nums[i].times = 0;
    nums[i].index = -1;
  }
  
  for (int i = 0; i < N; ++i)
  {
    int temp;
    scanf("%d", &temp);
    ++nums[temp-1].times;
    nums[temp-1].index = i;
  }

  int minIndex = N;
  int data;
  for (int i = 0; i < total; ++i)
  {
    if (nums[i].times == 1 && nums[i].index < minIndex)
    {
      minIndex = nums[i].index;
      data = i+1;
    }
  }

  if (minIndex != N)
    printf("%d\n", data);
  else
    printf("None\n");

  return 0;
}

