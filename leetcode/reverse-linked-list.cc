/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    ListNode *x = head, *y = head->next, *z;
    while (y) {
      z = y->next;
      y->next = x;
      x = y;
      y = z;
    }
    head->next = NULL;
    return x;
  }
};
