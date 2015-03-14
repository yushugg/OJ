/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>

class BSTIterator {
private:
  std::stack<TreeNode*> data;

public:
  BSTIterator(TreeNode *root) {
    // Iterate to the leftest
    while (root)
    {
      data.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !data.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* top = data.top();
    data.pop();

    if (top->right)
    {
      TreeNode* node = top->right;
      while (node)
      {
        data.push(node);
        node = node->left;
      }
    }

    return top->val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
