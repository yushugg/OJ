#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::vector<std::vector<int> > levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int> > levelOrder;
    if (!root)
      return levelOrder;

    std::queue<TreeNode*> queue;
    std::queue<int> level;
    queue.push(root);
    level.push(0);

    int currentLevel = 0;
    std::vector<int> itemVec;
    while (!queue.empty())
    {
      TreeNode* node = queue.front();
      int nodeLevel = level.front();
      queue.pop();
      level.pop();

      if (currentLevel != nodeLevel)
      {
        currentLevel = nodeLevel;
        levelOrder.push_back(itemVec);
        itemVec.clear();
      }
      itemVec.push_back(node->val);

      if (node->left)
      {
        queue.push(node->left);
        level.push(nodeLevel + 1);
      }
      if (node->right)
      {
        queue.push(node->right);
        level.push(nodeLevel + 1);
      }
    }
    levelOrder.push_back(itemVec);

    std::reverse(levelOrder.begin(), levelOrder.end());

    return levelOrder;
  }
};
