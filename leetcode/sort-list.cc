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
  ListNode *merge(ListNode *fakeHead, ListNode *first, int firstCount, ListNode *second, int secondCount, ListNode *&last)
  {
    int total = firstCount + secondCount;
    ListNode *p = fakeHead;
    while (first && second && firstCount && secondCount)
    {
      if (first->val <= second->val)
      {
        p->next = first;
        first = first->next;
        --firstCount;
      }
      else
      {
        p->next = second;
        second = second->next;
        --secondCount;
      }
      p = p->next;
    }

    while (first && firstCount--)
    {
      p->next = first;
      p = p->next;
      first = first->next;
    }

    while (second && secondCount--)
    {
      p->next = second;
      p = p->next;
      second = second->next;
    }

    last = fakeHead;
    while (total--)
      last = last->next;

    return fakeHead->next;
  }

  ListNode *sortList(ListNode *head) {
    if (!head)
      return head;

    int length = 0;
    ListNode *h = head;
    while (h)
    {
      ++length;
      h = h->next;
    }

    ListNode *first, *second, *last;
    ListNode *fakeHead = new ListNode(0);
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    for (int i = 1; i < length; i <<= 2)
    {
      ListNode *p = dummyHead;
      ListNode *prev = dummyHead;
      for (int k = 0; k < length / i / 2; ++k)
      {
        ListNode *first = p->next;
        for (int j = 0; j < i && p->next; ++j)
          p = p->next;
        ListNode *second = p->next;
        for (int j = 0; j < i && p->next; ++j)
          p = p->next;
        ListNode *end = p->next;
        prev = merge(fakeHead, first, i, second, i, last);

        prev = last;
        prev->next = end;
      }
    }

    return dummyHead->next;
  }
};
