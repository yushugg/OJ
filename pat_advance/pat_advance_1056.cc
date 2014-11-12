#include <cstdio>

int main()
{
  freopen("in.txt", "r", stdin);

  int numOfNumbers, group;
  int weights[1000], orders[1000], ranks[1000];
  bool visited[1000];

  scanf("%d%d", &numOfNumbers, &group);
  for (int i = 0; i < numOfNumbers; ++i)
    scanf("%d", &weights[i]);
  for (int i = 0; i < numOfNumbers; ++i)
    scanf("%d", &orders[i]);
  for (int i = 0; i < numOfNumbers; ++i)
    visited[i] = false;

  int groups = (numOfNumbers - 1) / group + 1;
  while (groups)
  {
    int count = 0;
    int maxWeight = -1;
    int maxIndex = -1;
    // playing by order
    for (int i = 0; i < numOfNumbers; ++i)
    {
      if (!visited[orders[i]])
      {
        ++count;
        if (maxWeight < weights[orders[i]])
        {
          maxWeight = weights[orders[i]];
          if (maxIndex != -1)
          {
            visited[maxIndex] = true;
            ranks[maxIndex] = groups + 1;
          }
          maxIndex = orders[i];
        }
        else
        {
          visited[orders[i]] = true;
          ranks[orders[i]] = groups + 1;
        }
        if (count == group)
        {
          count = 0;
          maxWeight = -1;
          maxIndex = -1;
        }
      }
    }

    if (groups == 1)
    {
      for (int i = 0; i < numOfNumbers; ++i)
      {
        if (!visited[i])
        {
          visited[i] = true;
          ranks[i] = 1;
          break;
        }
      }
      break;
    }
    groups = (groups - 1) / group + 1;
  }

  for (int i = 0; i < numOfNumbers - 1; ++i)
    printf("%d ", ranks[i]);
  printf("%d\n", ranks[numOfNumbers - 1]);

  return 0;
}

