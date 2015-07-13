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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int minVal = min(p->val, q->val);
    int maxVal = max(p->val, q->val);
    while (root->val < minVal || root->val > maxVal) {
      if (root->val > maxVal) root = root->left;
      else root = root->right;
    }
    return root;
  }
};
