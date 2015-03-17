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
  ListNode *partition(ListNode *head, int x) {
    ListNode* prev = new ListNode(x);
    prev->next = head;

    ListNode* largePrev = prev;
    while (largePrev->next && largePrev->next->val < x)
      largePrev = largePrev->next;
    ListNode* smallPrev = largePrev;
    while (smallPrev->next && smallPrev->next->val >= x)
      smallPrev = smallPrev->next;

    if (!largePrev || !smallPrev)
      return head;

    while (smallPrev->next)
    {
      ListNode* small = smallPrev->next;
      ListNode* smallNext = small->next;
      ListNode* large = largePrev->next;
      small->next = large;
      largePrev->next = small;
      smallPrev->next = smallNext;
      
      // Update
      largePrev = small;
      while (smallPrev->next && smallPrev->next->val >= x)
        smallPrev = smallPrev->next;
    }

    return prev->next;
  }
};
