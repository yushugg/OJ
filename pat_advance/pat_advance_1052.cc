#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

struct Node
{
  int address;
  int key;
};

int main()
{
  freopen("in.txt", "r", stdin);

  int N, start;
  scanf("%d%d", &N, &start);

  // address -> next, key
  std::map<int, Node> nodesMap;
  std::vector<Node> nodesList;

  for (int i = 0; i < N; ++i)
  {
    Node node;
    int addr;
    scanf("%d%d%d", &addr, &node.key, &node.address);
    nodesMap.insert(std::make_pair(addr, node));
  }

  while (start != -1)
  {
    Node node;
    node.address = start;
    node.key = nodesMap[start].key;
    nodesList.push_back(node);

    start = nodesMap[start].address;
  }

  std::sort(nodesList.begin(), nodesList.end(), [](Node n1, Node n2) -> bool {
    return n1.key < n2.key;
  });

  if (nodesList.size())
    printf("%lu %05d\n", nodesList.size(), nodesList.front().address);
  else
    printf("%lu -1\n", nodesList.size());
  
  for (size_t i = 0; i < nodesList.size(); ++i)
  {
    printf("%05d %d ", nodesList[i].address, nodesList[i].key);
    if (i < nodesList.size() - 1)
      printf("%05d\n", nodesList[i+1].address);
    else
      printf("-1\n");
  }

  return 0;
}

