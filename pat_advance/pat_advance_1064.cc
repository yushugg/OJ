#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

struct Node
{
  int value;
  int level;
  Node* left;
  Node* right;
};

int countNodes(Node* root)
{
  if (root == NULL)
    return 0;
  else
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void setRoot(Node* root, int* values, int numOfNodes)
{
  if (root)
  {
    int rightNodes = countNodes(root->right);
    root->value = values[numOfNodes - rightNodes - 1];
    setRoot(root->left, values, numOfNodes - rightNodes - 1);
    setRoot(root->right, values + (numOfNodes - rightNodes), rightNodes);
  }
}

Node* constructTree(Node* root, int level)
{
  if (root->level == level)
    return NULL;

  Node* temp = new Node;
  temp->level = root->level + 1;

  temp->left = constructTree(temp, level);
  temp->right = constructTree(temp, level);

  return temp;
}

void levelOrderTraversal(Node* root)
{
  std::queue<Node*> q;
  q.push(root);

  while (!q.empty())
  {
    Node* node = q.front();
    q.pop();
    if (node != root)
      printf(" %d", node->value);
    else
      printf("%d", node->value);

    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
  putchar('\n');
}

void lastLevel(Node* root, int level, int last)
{
  std::queue<Node*> q;
  q.push(root);
  int count = 0;

  while (!q.empty())
  {
    Node* node = q.front();
    q.pop();

    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);

    if (node->level == level - 1)
    {
      if (count < last)
      {
        Node* left = new Node;
        left->level = level;
        left->left = NULL;
        left->right = NULL;
        node->left = left;
        ++count;
      }
      if (count < last)
      {
        Node* right = new Node;
        right->level = level;
        right->left = NULL;
        right->right = NULL;
        node->right = right;
        ++count;
      }
    }
  }
}

int main()
{
  freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);
  int numbers[1000];
  for (int i = 0; i < N; ++i)
    scanf("%d", &numbers[i]);

  std::sort(numbers, numbers+N);

  int height = static_cast<int>(log(N+1) / log(2));
  if (N >= static_cast<int>(pow(2, height)))
    ++height;
  int last = N + 1 - static_cast<int>(pow(2, height - 1));
  if (height == 1)
  {
    printf("%d\n", numbers[0]);
    return 0;
  }
  
  // Construct the tree
  Node* root = new Node;
  root->level = 1;
  root->left = constructTree(root, height-1);
  root->right = constructTree(root, height-1);

  lastLevel(root, height, last);
  setRoot(root, numbers, N);
  levelOrderTraversal(root);

  return 0;
}

