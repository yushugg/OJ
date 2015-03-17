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
  TreeNode* build(std::vector<int>& inorder, int inStart, int inEnd, std::vector<int>& postorder, int postStart, int postEnd)
  {
    if (inStart > inEnd)
      return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);

    // Partition
    int relativeIdx = std::find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, root->val) - inorder.begin() - inStart;
    root->left = build(inorder, inStart, inStart + relativeIdx - 1, postorder, postStart, postStart + relativeIdx - 1);
    root->right = build(inorder, inStart + relativeIdx + 1, inEnd, postorder, postStart + relativeIdx, postEnd - 1);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
};
