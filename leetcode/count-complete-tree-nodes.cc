#include <cstdio>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    TreeNode *l = root, *r = root;
    int lc = 1, rc = 1;
    while (l->left) { l = l->left; ++lc; }
    while (r->right) { r = r->right; ++rc; }
    if (lc == rc) return (1 << lc) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  Solution solution;
  printf("%d\n", solution.countNodes(root));

  return 0;
}
