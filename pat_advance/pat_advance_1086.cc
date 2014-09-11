#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

struct Node
{
  int val;
  Node* left;
  Node* right;
  Node* parent;
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

int main()
{
  freopen("in.txt", "r", stdin);

  std::stack<int> nodeStack;
  int N;
  scanf("%d", &N);

  // Construct root node
  char action[5];
  scanf("%s", action);
  int value;
  scanf("%d", &value);
  Node* root = new Node;
  root->val = value;
  root->parent = NULL;
  root->left = NULL;
  root->right = NULL;
  nodeStack.push(root->val);

  Node* previous = root;

  bool addToLeft = true;
  bool isLeft = true;

  for (int i = 0; i < N * 2 - 1; ++i)
  {
    scanf("%s", action);
    
    if (strcmp(action, "Push") == 0)
    {
      scanf("%d", &value);

      Node* p = new Node;
      p->val = value;
      p->parent = previous;
      p->left = NULL;
      p->right = NULL;
      nodeStack.push(value);

      if (addToLeft)
      {
        previous->left = p;
        isLeft = true;
      }
      else
      {
        previous->right = p;
        isLeft = false;
      }

      addToLeft = true;

      previous = p;
    }
    else
    {
      addToLeft = false;
      int val = nodeStack.top();
      nodeStack.pop();
      if (!isLeft || previous->val != val)
        previous = previous->parent;
    }
  }

  // Output
  std::vector<int> out;
  postTraversal(root, out);

  for (size_t i = 0; i < out.size() - 1; ++i)
    printf("%d ", out[i]);
  printf("%d\n", out[out.size()-1]);

  return 0;
}

