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
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> inorderValues;

    // Push left nodes
    TreeNode* node = root;
    while (node)
    {
      stack.push(node);
      node = node->left;
    }

    while (!stack.empty())
    {
      TreeNode* node = stack.top();
      inorderValues.push_back(node->val);
      stack.pop();

      // If right nodes exist
      if (node->right)
      {
        // Push left nodes
        TreeNode* temp = node->right;
        while (temp)
        {
          stack.push(temp);
          temp = temp->left;
        }
      }
    }

    return inorderValues;
  }
};
