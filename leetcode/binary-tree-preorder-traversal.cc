/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>

class Solution {
private:
  std::stack<TreeNode*> stack;

public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> preorderValues;

    if (root)
    {
      stack.push(root);
      while (!stack.empty())
      {
        TreeNode* node = stack.top();
        stack.pop();
        preorderValues.push_back(node->val);
        if (node->right)
          stack.push(node->right);
        if (node->left)
          stack.push(node->left);
      }
    }

    return preorderValues;
  }
};
