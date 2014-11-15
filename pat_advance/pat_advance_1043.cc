#include <cstdio>
#include <vector>

struct Node
{
  int key;
  Node* left;
  Node* right;
};

void postOrder(Node* root, std::vector<int>& postOrderVec)
{
  if (!root)
    return ;

  postOrder(root->left, postOrderVec);
  postOrder(root->right, postOrderVec);
  postOrderVec.push_back(root->key);
}

bool testBST(int* seq, int length, bool mirror)
{
  if (!length)
    return true;

  int root = seq[0];
  int leftLength = length - 1;
  for (int i = 1; i < length; ++i)
  {
    if ((!mirror && seq[i] >= root) || (mirror && seq[i] < root))
    {
      leftLength = i - 1;
      break;
    }
  }

  // Check left
  for (int i = 1; i < leftLength + 1; ++i)
  {
    if (!mirror && seq[i] >= root)
      return false;
    if (mirror && seq[i] < root)
      return false;
  }

  // Check right
  for (int i = leftLength + 1; i < length; ++i)
  {
    if (!mirror && seq[i] < root)
      return false;
    if (mirror && seq[i] >= root)
      return false;
  }

  bool checkLeft = testBST(seq + 1, leftLength, mirror);
  bool checkRight = testBST(seq + leftLength + 1, length - leftLength - 1, mirror);

  return checkLeft && checkRight;
}

Node* constructBST(int* seq, int length, bool mirror)
{
  if (!length)
    return NULL;

  Node* node = new Node;
  node->key = seq[0];
  int leftLength = length - 1;
  for (int i = 1; i < length; ++i)
  {
    if ((!mirror && seq[i] >= seq[0]) || (mirror && seq[i] < seq[0]))
    {
      leftLength = i - 1;
      break;
    }
  }

  node->left = constructBST(seq + 1, leftLength, mirror);
  node->right = constructBST(seq + leftLength + 1, length - leftLength - 1, mirror);

  return node;
}

int main()
{
  //freopen("in.txt", "r", stdin);

  int N;
  scanf("%d", &N);

  int seq[1000];
  for (int i = 0; i < N; ++i)
    scanf("%d", &seq[i]);

  bool notMirror = testBST(seq, N, false);
  bool mirror = testBST(seq, N, true);
  bool bst = notMirror || mirror;
  if (!bst)
    printf("NO\n");
  else
  {
    Node* root = constructBST(seq, N, mirror);
    printf("YES\n");
    std::vector<int> postOrderVec;
    postOrder(root, postOrderVec);

    for (size_t i = 0; i != postOrderVec.size() - 1; ++i)
      printf("%d ", postOrderVec[i]);
    printf("%d\n", postOrderVec[postOrderVec.size() - 1]);
  }

  return 0;
}

