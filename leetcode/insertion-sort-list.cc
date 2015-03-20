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
  ListNode *insertionSortList(ListNode *head) {
    ListNode* headPrevious = new ListNode(0);
    headPrevious->next = head;

    ListNode* outer = headPrevious;
    while (outer->next)
    {
      ListNode* node = outer->next;
      ListNode* temp = node->next;
      ListNode* inner = headPrevious;
      while (inner->next && inner->next->val < node->val)
        inner = inner->next;
      if (node == inner->next)
        outer = outer->next;
      else
      {
        node->next = inner->next;
        inner->next = node;
        outer->next = temp;
      }
    }

    ListNode* currentHead = headPrevious->next;
    delete headPrevious;

    return currentHead;
  }
};
