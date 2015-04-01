/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <climits>

class Solution {
public:
  bool isValid(TreeNode *root, long long min, long long max) {
    if (!root)
      return true;

    if (root->val >= max || root->val <= min)
      return false;

    return isValid(root->left, min, root->val) & isValid(root->right, root->val, max);
  }

  bool isValidBST(TreeNode *root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
  }
};
