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
#include <vector>

class Solution {
private:
  std::stack<std::pair<TreeNode*, bool> > stack;

public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> traversal;
    if (!root)
      return traversal;

    while (root->left)
    {
      stack.push(std::make_pair(root, false));
      root = root->left;
    }
    stack.push(std::make_pair(root, false));

    while (!stack.empty())
    {
      std::pair<TreeNode*, bool> node = stack.top();
      if (node.second)
      {
        traversal.push_back(node.first->val);
        stack.pop();
      }
      else
      {
        // Check right subtree
        node.second = true;
        stack.pop();
        stack.push(node);
        if (node.first->right)
        {
          TreeNode* temp = node.first->right;
          while (temp->left)
          {
            stack.push(std::make_pair(temp, false));
            temp = temp->left;
          }
          stack.push(std::make_pair(temp, false));
        }
      }
    }

    return traversal;
  }
};
