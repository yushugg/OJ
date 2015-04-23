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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode *p = fakeHead;
    while (p->next) {
      if (p->next->val == val) {
        // Remove it
        p->next = p->next->next;
      } else
        p = p->next;
    }
    return fakeHead->next;
  }
};
