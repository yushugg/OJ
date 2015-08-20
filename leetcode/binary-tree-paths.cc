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
  void dfs(vector<string>& paths, string& current_path, TreeNode* root) {
    if (!root->left && !root->right) {
      current_path += to_string(root->val);
      paths.push_back(current_path);
      return ;
    }
    current_path += to_string(root->val) + string("->");
    string temp = current_path;
    if (root->left) dfs(paths, current_path, root->left);
    current_path = string(temp);
    if (root->right) dfs(paths, current_path, root->right);
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return vector<string>();
    vector<string> paths;
    string current_path;
    dfs(paths, current_path, root);
    return paths;
  }
};
