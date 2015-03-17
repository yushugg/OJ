/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>

class Solution {
public:
  TreeNode* build(std::vector<int>& preorder, int preStart, int preEnd, std::vector<int>& inorder, int inStart, int inEnd)
  {
    if (inStart > inEnd)
      return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int delta = std::find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, root->val) - inorder.begin() - inStart;

    root->left = build(preorder, preStart + 1, preStart + delta, inorder, inStart, inStart + delta - 1);
    root->right = build(preorder, preStart + delta + 1, preEnd, inorder, inStart + delta + 1, inEnd);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
};
