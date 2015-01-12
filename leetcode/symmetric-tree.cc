#include <cstdio>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool areTwoTreesSymmetric(TreeNode* root1, TreeNode* root2)
  {
    if (!root1 && !root2)
      return true;

    if (!root1 || !root2)
      return false;

    if (root1->val != root2->val)
      return false;

    return areTwoTreesSymmetric(root1->left, root2->right) && areTwoTreesSymmetric(root1->right, root2->left);
  }

  bool isSymmetric(TreeNode* root) {
    if (!root)
      return true;

    return areTwoTreesSymmetric(root->left, root->right);
  }
};

