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
  vector<int> inorder(TreeNode *root) {
    vector<int> in;
    TreeNode *cur = root, *prev;
    while (cur) {
      if (!cur->left) {
        in.push_back(cur->val);
        cur = cur->right;
      } else {
        prev = cur->left;
        while (prev->right && prev->right != cur) prev = prev->right;
        if (!prev->right) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = NULL;
          in.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return in;
  }

  int kthSmallest(TreeNode* root, int k) {
    vector<int> in = inorder(root);
    return in[k - 1];
  }
};
