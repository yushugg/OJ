#include <cstdio>
#include <vector>

struct Range
{
  int start;
  int end;
  int sum;
};

int main()
{
  int N, M;
  scanf("%d%d", &N, &M);
  
  int* diamonds = new int[N];
  for (int i = 0; i < N; ++i)
    scanf("%d", &diamonds[i]);

  std::vector<Range> ranges;
  int sum = 0;
  int end = 0;
  for (int i = 0; i < N; ++i)
  {
    sum += diamonds[end++];
    if (sum >= M)
    {
      Range range;
      range.start = 0;
      range.end = end - 1;
      range.sum = sum;
      ranges.push_back(range);

      break;
    }
  }

  for (int i = 1; i < N; ++i)
  {
    sum -= diamonds[i - 1];
    if (sum >= M)
    {
      // decrease from end to front until find the suitable
      do {
        sum -= diamonds[--end];
      } while (sum >= M);
      Range range;
      range.start = i;
      range.end = end;
      // Add back sum
      sum += diamonds[end++];
      range.sum = sum;
      ranges.push_back(range);
    }
    else
    {
      while (sum < M && end < N)
        sum += diamonds[end++];

      if (sum >= M)
      {
        Range range;
        range.start = i;
        range.end = end - 1;
        range.sum = sum;
        ranges.push_back(range);
      }
      else
        break;
    }
  }

  int min = ranges[0].sum;
  for (auto iter = ranges.begin(); iter != ranges.end(); ++iter)
    if (min > iter->sum)
      min = iter->sum;

  for (auto iter = ranges.begin(); iter != ranges.end(); ++iter)
    if (iter->sum == min)
      printf("%d-%d\n", iter->start + 1, iter->end + 1);

  delete[] diamonds;

  return 0;
}

