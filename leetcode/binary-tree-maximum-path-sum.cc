/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int dfs(TreeNode* root, int& maxSum) {
    if (!root->left && !root->right) {
      maxSum = max(maxSum, root->val);
      return 0;
    }
    int leftMax = 0, rightMax = 0;
    if (root->left) leftMax = max(0, dfs(root->left, maxSum) + root->left->val);
    if (root->right) rightMax = max(0, dfs(root->right, maxSum) + root->right->val);
    maxSum = max(maxSum, leftMax + root->val + rightMax);
    return max(leftMax, rightMax);
  }

  int maxPathSum(TreeNode* root) {
    int max = INT_MIN;
    dfs(root, max);
    return max;
  }
};
