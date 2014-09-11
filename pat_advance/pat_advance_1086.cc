#include <cstdio>
#include <cstring>
#include <vector>

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

  Node* previous = root;
  // Insert at left
  bool isLeft = true;
  bool mustPop = true;

  for (int i = 0; i < N * 2; ++i)
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
      if (isLeft)
      {
        previous->left = p;
        mustPop = false;
      }
      else
      {
        previous->right = p;
        mustPop = true;
      }
      isLeft = true;

      previous = p;
    }
    else
    {
      if (mustPop)
        previous = previous->parent;
      else
        mustPop = true;
      isLeft = false;
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

