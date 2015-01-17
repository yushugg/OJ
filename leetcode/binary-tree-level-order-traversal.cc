#include<cstdio>
#include<queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::vector<std::vector<int> > levelOrder(TreeNode *root) {
    std::vector<std::vector<int> > levelOrderVecs;

    std::queue<TreeNode*> q;
    std::queue<int> levelQueue;
    if (root)
    {
      q.push(root);
      levelQueue.push(0);
    }
    else
      return levelOrderVecs;

    int currentLevel = 0;
    std::vector<int> itemVec;
    while (!q.empty())
    {
      TreeNode* node = q.front();
      int level = levelQueue.front();
      q.pop();
      levelQueue.pop();

      // Record
      if (currentLevel != level)
      {
        currentLevel = level;
        levelOrderVecs.push_back(itemVec);
        itemVec.clear();
      }
      itemVec.push_back(node->val);

      if (node->left)
      {
        q.push(node->left);
        levelQueue.push(level + 1);
      }
      if (node->right)
      {
        q.push(node->right);
        levelQueue.push(level + 1);
      }
    }
    levelOrderVecs.push_back(itemVec);

    return levelOrderVecs;
  }
};
