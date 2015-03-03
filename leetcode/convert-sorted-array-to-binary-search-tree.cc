/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* bst(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end)
      return NULL;

    std::vector<int>::iterator mid = begin + (end - begin) / 2;
    TreeNode* node = new TreeNode(*mid);

    node->left = bst(begin, mid);
    node->right = bst(mid + 1, end);

    return node;
  }

  TreeNode *sortedArrayToBST(std::vector<int> &num) {
    return bst(num.begin(), num.end());
  }
};

int main(int argc, char* argv[])
{
  return 0;
};
