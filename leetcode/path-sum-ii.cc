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
  void iterateNode(std::vector<std::vector<int> >& paths, std::vector<int> currentPath, int currentSum, int sum, TreeNode* root)
  {
    currentPath.push_back(root->val);
    currentSum += root->val;
    if (!root->left && !root->right && currentSum == sum)
      paths.push_back(currentPath);

    if (root->left)
      iterateNode(paths, currentPath, currentSum, sum, root->left);
    if (root->right)
      iterateNode(paths, currentPath, currentSum, sum, root->right);
  }

  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    std::vector<std::vector<int> > paths;
    std::vector<int> currentPath;
    if (!root)
      return paths;

    iterateNode(paths, currentPath, 0, sum, root);
  }
};
