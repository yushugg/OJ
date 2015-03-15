/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* listToBST(ListNode* head, int n)
  {
    if (!n)
      return NULL;

    int mid = n / 2;
    ListNode* p = head;
    int count = 0;
    while (count < mid)
    {
      ++count;
      p = p->next;
    }

    TreeNode* root = new TreeNode(p->val);
    root->left = listToBST(head, mid);
    root->right = listToBST(p->next, n - mid - 1);

    return root;
  }

  TreeNode *sortedListToBST(ListNode *head) {
    int n = 0;
    ListNode* p = head;
    while (p)
    {
      ++n;
      p = p->next;
    }

    return listToBST(head, n);
  }
};
