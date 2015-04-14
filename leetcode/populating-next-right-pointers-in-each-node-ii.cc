#include <cstdio>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    while (root) {
      TreeLinkNode *prev = NULL;
      TreeLinkNode *p = root;
      root = NULL;
      while (p) {
        if (p->left && p->right) {
          if (prev) prev->next = p->left;
          p->left->next = p->right;
          prev = p->right;
          if (!root) root = p->left;
        } else if (p->left && !p->right) {
          if (prev) prev->next = p->left;
          prev = p->left;
          if (!root) root = p->left;
        } else if (!p->left && p->right) {
          if (prev) prev->next = p->right;
          prev = p->right;
          if (!root) root = p->right;
        }

        p = p->next;
      }
    }
  }
};

int main()
{
  TreeLinkNode *root = new TreeLinkNode(1);
  TreeLinkNode *leftNode = new TreeLinkNode(2);
  root->left = leftNode;

  Solution s;
  s.connect(root);

  return 0;
}

