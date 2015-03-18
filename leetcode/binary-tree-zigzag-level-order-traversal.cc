#include <queue>
#include <vector>
#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::vector<std::vector<int> > zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int> > result;
    if (!root)
      return result;

    std::queue<TreeNode*> queue;
    bool leftToRight = true;
    queue.push(root);
    queue.push(NULL);
    std::vector<int> level;
    while (!queue.empty())
    {
      TreeNode* node = queue.front();
      queue.pop();
      if (node)
      {
        // Reversed insert or not
        if (leftToRight)
          level.push_back(node->val);
        else
          level.insert(level.begin(), node->val);

        if (node->left)
          queue.push(node->left);
        if (node->right)
          queue.push(node->right);
      }
      else
      {
        // Add to result
        result.push_back(level);
        level.clear();
        leftToRight = !leftToRight;

        if (!queue.empty())
          queue.push(NULL);
      }
    }

    return result;
  }
};

void inorder(TreeNode* root)
{
  if (!root)
    return ;

  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

int main(int argc, char* argv[])
{
  // Construct a tree
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution s;
  // Test
  inorder(root);
  putchar('\n');

  std::vector<std::vector<int> > result = s.zigzagLevelOrder(root);
  for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1)
  {
    putchar('[');
    for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2)
    {
      printf("%d ", *iter2);
    }
    printf("],\n");
  }

  return 0;
}

