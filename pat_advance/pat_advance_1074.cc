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

int main()
{
  freopen("in.txt", "r", stdin);
  char root[6];
  int N, K;
  scanf("%s%d%d", root, &N, &K);

  for (int i = 0; i < N; ++i)
  {
    char addr[6];
    Node node;
    scanf("%s%d%s", addr, &node.data, node.next);
    list.insert(std::make_pair(addr, node));
  }

  // Iterate
  printf("%d\n", list.size());
  for (std::map<const char*, Node, cmp_str>::iterator iter = list.begin(); iter != list.end(); ++iter)
    printf("%s %d %s\n", iter->first, (iter->second).data, (iter->second).next);

  return 0;
}

