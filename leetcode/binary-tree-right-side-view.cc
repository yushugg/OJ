/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    if (!root)
      return result;

    std::queue<TreeNode*> queue;
    queue.push(root);
    queue.push(NULL);
    int value;
    while (!queue.empty())
    {
      TreeNode *node = queue.front();
      queue.pop();

      if (node)
      {
        value = node->val;
        if (node->left)
          queue.push(node->left);
        if (node->right)
          queue.push(node->right);
      }
      else
      {
        result.push_back(value);
        if (queue.empty())
          break;
        queue.push(NULL);
      }
    }

    return result;
  }
};
