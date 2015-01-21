#include <cstdio>
#include <queue>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  // Using BFS
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
      return false;

    std::queue<TreeNode*> nodeQueue;
    std::queue<int> sumQueue;
    nodeQueue.push(root);
    sumQueue.push(root->val);

    while (!nodeQueue.empty())
    {
      TreeNode* node = nodeQueue.front();
      int temp = sumQueue.front();
      nodeQueue.pop();
      sumQueue.pop();

      if (!node->left && !node->right && temp == sum)
        return true;

      if (node->left)
      {
        nodeQueue.push(node->left);
        sumQueue.push(temp + node->left->val);
      }
      if (node->right)
      {
        nodeQueue.push(node->right);
        sumQueue.push(temp + node->right->val);
      }
    }

    return false;
  }

  bool DFS(TreeNode* root, int parentSum, int sum) {
    // If leaf
    if (!root->left && !root->right)
      return parentSum + root->val == sum;

    bool left = false;
    bool right = false;
    if (root->left)
      left = DFS(root->left, parentSum + root->val, sum);
    if (root->right)
      right = DFS(root->right, parentSum + root->val, sum);

    return left | right;
  }

  // Using DFS
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
      return false;

    return DFS(root, 0, sum);
  }
};
