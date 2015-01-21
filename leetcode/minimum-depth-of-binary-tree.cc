#include <queue>
#include <algorithm>

class Solution {
public:
  // BFS
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;

    std::queue<TreeNode*> nodeQueue;
    std::queue<int> levelQueue;
    nodeQueue.push(root);
    levelQueue.push(1);

    while (!nodeQueue.empty())
    {
      TreeNode* node = nodeQueue.front();
      int level = levelQueue.front();
      nodeQueue.pop();
      levelQueue.pop();

      if (!node->left && !node->right)
        return level;

      if (node->left)
      {
        nodeQueue.push(node->left);
        levelQueue.push(level + 1);
      }
      if (node->right)
      {
        nodeQueue.push(node->right);
        levelQueue.push(level + 1);
      }
    }

    return 0;
  }

  // DFS
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;

    if (!root->left)
      return minDepth(root->right) + 1;
    if (!root->right)
      return minDepth(root->left) + 1;

    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};
