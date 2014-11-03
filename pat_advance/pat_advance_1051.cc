#include <cstdio>
#include <stack>

bool check(const int seq[], const int length, const int capacity)
{
  std::stack<int> st;
  int left = 1;

  for (int i = 0; i < length; ++i)
  {
    // Push from left to seq[i]
    for ( ; left <= seq[i]; ++left)
    {
      if (st.size() < capacity)
        st.push(left);
    }
    // Then pop the last
    int out = st.top();
    st.pop();
    if (out != seq[i])
      return false;
  }

  return true;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int capacity, length, numOfCheckList;
  scanf("%d%d%d", &capacity, &length, &numOfCheckList);

  for (int i = 0; i < numOfCheckList; ++i)
  {
    int* seq = new int[length];
    for (int j = 0; j < length; ++j)
      scanf("%d", &seq[j]);

    if (check(seq, length, capacity))
      printf("YES\n");
    else
      printf("NO\n");

    delete[] seq;
  }

  return 0;
}

