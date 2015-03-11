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
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast, *slow;
    fast = slow = head;

    bool noCycle = true;
    while (slow && fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
      {
        noCycle = false;
        break;
      }
    }

    if (noCycle)
      return NULL;
    else
    {
      ListNode* entry = head;
      while (slow != entry)
      {
        slow = slow->next;
        entry = entry->next;
      }

      return entry;
    }
  }
};
