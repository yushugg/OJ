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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode* previousHead = new ListNode(0);
    previousHead->next = head;
    ListNode* start, *end;
    start = end = previousHead;

    while (start->next)
    {
      end = start->next;
      bool deleteNode = false;
      while (end->next)
      {
        if (start->next->val == end->next->val)
        {
          deleteNode = true;
          end = end->next;
        }
        else
          break;
      }

      // delete nodes
      if (deleteNode)
        start->next = end->next;
      else
        start = start->next;
    }

    ListNode* returnHead = previousHead->next;
    delete previousHead;

    return returnHead;
  }
};
