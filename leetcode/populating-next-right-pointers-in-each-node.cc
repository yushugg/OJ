/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <queue>

class Solution {
private:
  std::queue<TreeLinkNode*> queue;

public:
  void connect(TreeLinkNode *root) {
    if (root)
      queue.push(root);

    int count = 0;
    int product = 2;
    while (!queue.empty())
    {
      TreeLinkNode* node = queue.front();
      queue.pop();
      ++count;

      if (!queue.empty() && count != product - 1)
        node->next = queue.front();

      if (count == product - 1)
        product *= 2;

      if (node->left)
        queue.push(node->left);
      if (node->right)
        queue.push(node->right);
    }
  }
};
