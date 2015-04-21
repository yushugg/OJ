#include <cstdio>
#include <stack>
#include <climits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void recoverTreeWithStack(TreeNode *root) {
    if (!root) return ;

    TreeNode *node1 = NULL, *node2 = NULL, *first = NULL, *mid = NULL, *last = NULL;
    std::stack<TreeNode*> stack;
    TreeNode *it = root;
    while (it->left) it = it->left; it->left = new TreeNode(INT_MIN);
    it = root; while (it->right) it = it->right; it->right = new TreeNode(INT_MAX);
    it = root; while (it) { stack.push(it); it = it->left; }
    while (!stack.empty()) {
      TreeNode *node = stack.top();
      stack.pop();
      if (!first) first = node;
      else if (!mid) mid = node;
      else if (!last) last = node;
      else { first = mid; mid = last; last = node; }
      // Test misplace node
      if (first && mid && last) {
        if (!node1 && first->val < mid->val && mid->val > last->val) node1 = mid;
        if (first->val > mid->val && mid->val < last->val) node2 = mid;
      }
      TreeNode *temp = node->right;
      while (temp) { stack.push(temp); temp = temp->left; }
    }

    it = root; while (it->left->left) it = it->left; it->left = NULL;
    it = root; while (it->right->right) it = it->right; it->right = NULL;
    int tmp = node1->val; node1->val = node2->val; node2->val = tmp;
  }

  void recoverTree(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL, *previous = NULL, *nodes[4];
    int count = 0;
    while (cur) {
      if (!cur->left) {
        if (previous && previous->val > cur->val) { nodes[count++] = previous; nodes[count++] = cur; }
        previous = cur;
        cur = cur->right;
      } else {
        prev = cur->left;
        while (prev->right && prev->right != cur) prev = prev->right;
        if (!prev->right) { prev->right = cur; cur = cur->left; }
        else {
          prev->right = NULL;
          if (previous && previous->val > cur->val) { nodes[count++] = previous; nodes[count++] = cur; }
          previous = cur;
          cur = cur->right;
        }
      }
    }
    printf("%d\n", count);
    TreeNode *error1, *error2;
    if (count == 2) { error1 = nodes[0]; error2 = nodes[1]; }
    else { error1 = nodes[0]; error2 = nodes[3]; }
    int tmp = error1->val; error1->val = error2->val; error2->val = tmp;
  }

  void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur) {
      if (!cur->left) {
        printf("%d--", cur->val);
        cur = cur->right;
      } else {
        // Find predecessor
        prev = cur->left;
        while (prev->right && prev->right != cur) prev = prev->right;
        if (!prev->right) { prev->right = cur; cur = cur->left; }
        else { prev->right = NULL; printf("%d--", cur->val); cur = cur->right; }
      }
    }
  }
};

int main() {
  TreeNode *root = new TreeNode(0);
  TreeNode *node = new TreeNode(1);
  root->left = node;
  Solution solution;
  solution.recoverTree(root);

  printf("%d,%d\n", root->val, root->left->val);
  solution.inorderMorrisTraversal(root);
  puts("");

  return 0;
}

