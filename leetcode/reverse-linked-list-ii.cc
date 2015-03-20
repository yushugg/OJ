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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head)
      return head;
    
    int delta = n - m;

    ListNode* originPrevious = new ListNode(0);
    originPrevious->next = head;
    ListNode* previous = originPrevious;
    while (previous->next && m > 1)
    {
      previous = previous->next;
      --m;
    }
    
    ListNode* p = previous->next;
    while (p->next && delta)
    {
      --delta;
      ListNode* temp = p->next;
      ListNode* tempNext = temp->next;
      temp->next = previous->next;
      previous->next = temp;
      p->next = tempNext;
    }

    ListNode* reversedHead = originPrevious->next;
    delete originPrevious;

    return reversedHead;
  }
};
