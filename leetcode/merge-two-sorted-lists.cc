#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1)
      return l2;
    if (!l2)
      return l1;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* head;
    if (p1->val < p2->val)
    {
      head = p1;
      p1 = p1->next;
    }
    else
    {
      head = p2;
      p2 = p2->next;
    }
    ListNode* h = head;

    while (p1 && p2)
    {
      if (p1->val < p2->val)
      {
        h->next = p1;
        p1 = p1->next;
      }
      else
      {
        h->next = p2;
        p2 = p2->next;
      }
      h = h->next;
    }

    if (p1)
      h->next = p1;
    if (p2)
      h->next = p2;

    return head;
  }
};

int main(int argc, char* argv[])
{
  return 0;
}

