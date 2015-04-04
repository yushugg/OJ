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

    while (root->right)
    {
      result.push_back(root->val);
      root = root->right;
    }
    result.push_back(root->val);

    vector<int> newGen = rightSideView(root->left);
    result.insert(result.end(), newGen.begin(), newGen.end());

    return result;
  }
};
