#include <cstdio>
#include <algorithm>

int putZero(int num[], int idxes[])
{
  int count = 0;
  while (num[0] != 0)
  {
    ++count;
    int zeroIdx = idxes[0];
    int swapIdx = idxes[zeroIdx];
    std::swap(num[zeroIdx], num[swapIdx]);
    idxes[0] = swapIdx;
    idxes[zeroIdx] = zeroIdx;
  }

  return count;
}

int main()
{
  int N;
  scanf("%d", &N);

  int* num = new int[N];
  int* idxes = new int[N];
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &num[i]);
    idxes[num[i]] = i;
  }

  int steps = putZero(num, idxes);
  bool done = true;
  int swapNum;
  for (int i = 0; i < N; ++i)
  {
    if (num[i] != i)
    {
      done = false;
      swapNum = i;
      break;
    }
  }

  while (!done)
  {
    done = true;
    std::swap(num[0], num[swapNum]);
    idxes[num[0]] = 0;
    idxes[num[swapNum]] = swapNum;
    ++steps;
    steps += putZero(num, idxes);
    for (int i = 0; i < N; ++i)
    {
      if (num[i] != i)
      {
        done = false;
        swapNum = i;
        break;
      }
    }
  }
  printf("%d\n", steps);

  delete[] num;

  return 0;
}

