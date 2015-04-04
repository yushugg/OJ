#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return ;
    ListNode *fakeHead = new ListNode(0);
    fakeHead->next = head;

    ListNode *slow, *fast;
    slow = fast = fakeHead;
    while (slow && fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse start postion
    ListNode *reverse = slow;
    ListNode *pr = reverse->next;
    while (pr->next)
    {
      ListNode *prNext = pr->next;
      ListNode *reverseNext = reverse->next;
      pr->next = prNext->next;
      reverse->next = prNext;
      prNext->next = reverseNext;
    }

    ListNode *start = head;
    while (reverse->next && reverse != start)
    {
      ListNode *rNext = reverse->next;
      ListNode *startNext = start->next;
      reverse->next = rNext->next;
      start->next = rNext;
      rNext->next = startNext;
      start = rNext->next;
    }
  }
};

int main()
{
  ListNode *head;
  head = new ListNode(1);
  ListNode *p = head;
  for (int i = 2; i <= 1; ++i)
  {
    ListNode *node = new ListNode(i);
    p->next = node;
    p = p->next;
  }

  Solution s;
  s.reorderList(head);

  while (head)
  {
    printf("%d ", head->val);
    head = head->next;
  }
  puts("");

  return 0;
}


