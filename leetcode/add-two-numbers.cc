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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int carry = 0;
    while (l1 && l2)
    {
      int sum = l1->val + l2->val + carry;
      carry = sum >= 10 ? 1 : 0;
      ListNode *node = new ListNode(sum % 10);
      p->next = node;
      p = p->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1)
    {
      int sum = l1->val + carry;
      carry = sum >= 10 ? 1 : 0;
      ListNode *node = new ListNode(sum % 10);
      p->next = node;
      p = p->next;
      l1 = l1->next;
    }

    while (l2)
    {
      int sum = l2->val + carry;
      carry = sum >= 10 ? 1 : 0;
      ListNode *node = new ListNode(sum % 10);
      p->next = node;
      p = p->next;
      l2 = l2->next;
    }
    
    if (carry)
    {
      ListNode *node = new ListNode(carry);
      p->next = node;
    }

    return head->next;
  }
};
