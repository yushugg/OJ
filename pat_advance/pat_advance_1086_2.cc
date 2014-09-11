#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

struct Node
{
  int val;
  Node* left;
  Node* right;
};

void postTraversal(Node* root, std::vector<int>& out)
{
  if (root)
  {
    postTraversal(root->left, out);
    postTraversal(root->right, out);
    out.push_back(root->val);
  }
}

Node* genTree(int* inOrder, int* pushOrder, int size)
{
  if (size <= 0)
    return NULL;

  Node* root = new Node;
  int value = pushOrder[0];
  int left = 1;
  int right = std::find(inOrder, inOrder+size, value) - inOrder + 1;

  root->val = value;
  root->left = genTree(inOrder, pushOrder+1, right - left);
  root->right = genTree(inOrder+right, pushOrder+right, size-right);

  return root;
}

int main()
{
  freopen("in.txt", "r", stdin);

  std::stack<int> nodeStack;
  int N;
  scanf("%d", &N);

  int inOrder[35];
  int pushOrder[35];

  // Construct root node
  int size1 = 0;
  int size2 = 0;
  for (int i = 0; i < N * 2; ++i)
  {
    char action[5];
    scanf("%s", action);
    if (strcmp(action, "Push") == 0)
    {
      int value;
      scanf("%d", &value);
      pushOrder[size1++] = value;
      nodeStack.push(value);
    }
    else
    {
      inOrder[size2++] = nodeStack.top();
      nodeStack.pop();
    }
  }

  Node* root = genTree(inOrder, pushOrder, N);

  // Output
  std::vector<int> out;
  postTraversal(root, out);

  for (size_t i = 0; i < out.size() - 1; ++i)
    printf("%d ", out[i]);
  printf("%d\n", out[out.size()-1]);

  return 0;
}

