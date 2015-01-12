#include <cstdio>
#include <algorithm>

/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int getHeight(TreeNode* root)
  {
    if (!root)
      return 0;
    
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
  }

  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;

    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (left - right > 1 || left - right < -1)
      return false;

    return isBalanced(root->left) && isBalanced(root->right);
  }
};

int main(int argc, char* argv[])
{
  return 0;
}

