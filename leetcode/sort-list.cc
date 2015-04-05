#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *merge(ListNode *first, ListNode *second, ListNode *last)
  {
    ListNode *f, *e;
    f = first->next;
    e = second->next;

    // Movement pointer
    ListNode *p = first;
    ListNode *secondNext = second->next;
    ListNode *lastNext = last->next;
    while (f != secondNext && e != lastNext)
    {
      if (f->val <= e->val)
      {
        p->next = f;
        f = f->next;
      }
      else
      {
        p->next = e;
        e = e->next;
      }
      p = p->next;
    }

    while (f != secondNext)
    {
      p->next = f;
      p = p->next;
      f = f->next;
    }

    while (e != lastNext)
    {
      p->next = e;
      p = p->next;
      e = e->next;
    }

    p->next = lastNext;

    // Return new last
    return p;
  }

  ListNode *sortList(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;

    // Count length
    int length = 0;
    ListNode *h = dummyHead;
    while (h->next)
    {
      ++length;
      h = h->next;
    }

    ListNode *first, *second, *last;
    for (int step = 1; step < length; step <<= 1)
    {
      first = dummyHead;
      while (first && first->next)
      {
        second = first;
        int s = step;
        while (second->next && s--)
          second = second->next;

        last = second;
        s = step;
        while (last->next && s--)
          last = last->next;

        // Merge and update first
        first = merge(first, second, last);
      }
    }

    return dummyHead->next;
  }
};

int main()
{
  ListNode *head = new ListNode(0);
  ListNode *p = head;
  int size;
  scanf("%d", &size);
  for (int i = 0; i < size; ++i)
  {
    int val;
    scanf("%d", &val);
    ListNode *node = new ListNode(val);
    p->next = node;
    p = p->next;
  }

  Solution s;
  ListNode *sortedList = s.sortList(head->next);

  // Output
  while (sortedList)
  {
    printf("%d->", sortedList->val);
    sortedList = sortedList->next;
  }
  puts("");

  return 0;
}


