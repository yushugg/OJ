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
  bool dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
    if (root == node) { path.push_back(root); return true; }
    if (root->left) {
      path.push_back(root);
      if (!dfs(root->left, node, path)) path.pop_back();
      else return true;
    }
    if (root->right) {
      path.push_back(root);
      if (!dfs(root->right, node, path)) path.pop_back();
      else return true;
    }
    return false;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> ppath, qpath;
    dfs(root, p, ppath);
    dfs(root, q, qpath);
    int i;
    for (i = 0; i < ppath.size() && i < qpath.size(); ++i) {
      if (ppath[i] != qpath[i]) return ppath[i - 1];
    }
    return ppath[i - 1];
  }
};
