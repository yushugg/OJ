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
  std::vector<TreeNode*> treesFromTo(int start, int end)
  {
    std::vector<TreeNode*> tree;
    if (start > end)
    {
      tree.push_back(NULL);
      return tree;
    }

    for (int mid = start; mid <= end; ++mid)
    {
      std::vector<TreeNode*> left = treesFromTo(start, mid - 1);
      std::vector<TreeNode*> right = treesFromTo(mid + 1, end);

      for (auto leftIter = left.begin(); leftIter != left.end(); ++leftIter)
      {
        for (auto rightIter = right.begin(); rightIter != right.end(); ++rightIter)
        {
          TreeNode* node = new TreeNode(mid);
          node->left = *leftIter;
          node->right = *rightIter;
          tree.push_back(node);
        }
      }
    }

    return tree;
  }

  std::vector<TreeNode *> generateTrees(int n) {
    return treesFromTo(1, n);
  }
};
