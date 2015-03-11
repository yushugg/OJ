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
  void DFS(TreeNode* root, int num, int& sum) {
    num = num * 10 + root->val;

    if (!root->left && !root->right)
    {
      sum += num;
      return ;
    }
    
    if (root->left)
      DFS(root->left, num, sum);
    if (root->right)
      DFS(root->right, num, sum);
  }

  int sumNumbers(TreeNode *root) {
    int sum = 0;
    if (root)
      DFS(root, 0, sum);
    
    return sum;
  }
};
