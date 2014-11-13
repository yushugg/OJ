#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

std::stack<int> stack;
int data[100001];

void push(int key)
{
  stack.push(key);
  ++data[key];
}

void pop()
{
  if (!stack.empty())
  {
    printf("%d\n", stack.top());
    if (data[stack.top()] > 0)
      --data[stack.top()];
    stack.pop();
  }
  else
    printf("Invalid\n");
}

void peekMedian()
{
  if (!stack.empty())
  {
    int median = stack.size() % 2 ? (stack.size() + 1) / 2 : stack.size() / 2;
    int i;
    int count = 0;
    for (i = 0; ; ++i)
    {
      int cnt = 0;
      while (data[i] > cnt)
        ++cnt;
      count += cnt;
      if (count >= median)
        break;
    }
    printf("%d\n", i);
  }
  else
    printf("Invalid\n");
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);
  for (int i = 0; i < 100001; ++i)
    data[i] = 0;

  for (int i = 0; i < N; ++i)
  {
    char* str = new char[11];
    scanf("%s", str);

    if (!strcmp(str, "Push"))
    {
      int key;
      scanf("%d", &key);

      push(key);
    } else if (!strcmp(str, "Pop"))
      pop();
    else
      peekMedian();

    delete[] str;
  }

  return 0;
}

