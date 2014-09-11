#include <cstdio>
#include <algorithm>

const int Num = 100000;

int binarySearch(int arr[], int N, int value)
{
  int low = 0;
  int high = N-1;

  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
    
    if (value < arr[mid])
      high = mid - 1;
    else if (value > arr[mid])
      low = mid + 1;
    else
      return mid;
  }

  if (arr[mid] > value)
    return mid - 1;
  else
    return mid;
}

int main()
{
  int N, p;
  scanf("%d%d", &N, &p);

  int arr[Num];

  for (int i = 0; i < N; ++i)
    scanf("%d", &arr[i]);

  std::sort(arr, arr+N);

  int perfect = 0;
  for (int i = 0; i < N; ++i)
  {
    int m = arr[i];
    int max = m * p;

    int perf;
    // If overflow
    if (max < m)
      perf = N - i;
    else
    {
      int index = binarySearch(arr, N, max);
      perf = index - i + 1;
    }

    if (perfect < perf)
      perfect = perf;
  }

  printf("%d\n", perfect);

  return 0;
}

