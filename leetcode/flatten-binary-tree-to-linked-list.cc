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
  TreeNode* run(TreeNode* root)
  {
    if (!root)
      return NULL;

    TreeNode* temp = root->right;
    TreeNode* leftResult = run(root->left);
    root->left = NULL;
    if (!leftResult)
      root->right = run(root->right);
    else
    {
      root->right = leftResult;
      TreeNode* leftResultRight = leftResult;
      while (leftResultRight->right)
        leftResultRight = leftResultRight->right;
      leftResultRight->right = run(temp);
      leftResultRight->left = NULL;
    }

    return root;
  }

  void flatten(TreeNode *root) {
    run(root);
  }
};
