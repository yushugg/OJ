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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head)
    {
      ListNode* prev = head;
      ListNode* p = head->next;
      while (p)
      {
        if (p->val == prev->val)
          prev->next = p->next;
        else
          prev = p;

        p = p->next;
      }
    }

    return head;
  }
};

int main(int argc, char* argv[])
{
  ListNode* head;

  return 0;
}

