#include <cstdio>
#include <cstring>
#include <map>

struct Node
{
  int data;
  char next[6];
};

struct cmp_str
{
  bool operator()(const char* str1, const char* str2)
  {
    return strcmp(str1, str2) < 0;
  }
};
std::map<const char*, Node, cmp_str> list;

// !Perhaps some input nodes are not in the list
int main()
{
  freopen("in.txt", "r", stdin);
  char root[6];
  int N, K;
  scanf("%s%d%d", root, &N, &K);

  for (int i = 0; i < N; ++i)
  {
    char* addr = new char[6];
    Node node;
    scanf("%s%d%s", addr, &node.data, node.next);
    list.insert(std::make_pair(addr, node));
  }

  // Calculate the real N
  char test[6];
  strcpy(test, root);
  N = 0;
  while (strcmp(test, "-1"))
  {
    strcpy(test, list[test].next);
    ++N;
  }

  char newRoot[6];
  strcpy(newRoot, root);
  char start[6];
  strcpy(start, root);
  char preEnd[6];
  for (int i = 0; i+K <= N; i += K)
  {
    int cnt = 0;
    char end[6];
    strcpy(end, start);
    // Find end, ie. next loop's start
    while (cnt < K)
    {
      strcpy(end, list[end].next);
      if (cnt == K-2)
      {
        if (i == 0)
          strcpy(newRoot, end);
        else
          strcpy(list[preEnd].next, end);
      }
      ++cnt;
    }

    char prev[6];
    strcpy(prev, end);
    char now[6];
    strcpy(now, start);
    cnt = 0;
    while(cnt < K)
    {
      char post[6];
      strcpy(post, list[now].next);
      strcpy(list[now].next, prev);
      // Update now, post
      strcpy(prev, now);
      strcpy(now, post);
      ++cnt;
    }

    // Update start
    strcpy(preEnd, start);
    strcpy(start, end);
  }

  // Iterate
  //printf("%d\n", list.size());
  int cnt = 0;
  char begin[6];
  strcpy(begin, newRoot);
  while (cnt < N)
  {
    printf("%s %d %s\n", begin, list[begin].data, list[begin].next);
    strcpy(begin, list[begin].next);
    ++cnt;
  }

  // Delete key's memory

  return 0;
}

