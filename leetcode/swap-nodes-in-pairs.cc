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
  ListNode *swapPairs(ListNode *head) {
    ListNode* p = head;
    if (p && p->next)
      head = p->next;
    else
      return head;

    ListNode* prev = new ListNode(0);
    while (p && p->next)
    {
      ListNode* nextPairs = p->next->next;
      ListNode* temp = p->next;
      p->next = nextPairs;
      temp->next = p;
      prev->next = temp;
      prev = p;
      p = nextPairs;
    }

    return head;
  }
};
