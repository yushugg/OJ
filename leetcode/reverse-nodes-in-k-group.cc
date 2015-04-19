#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverse(ListNode *head, ListNode *fakeHead, int k) {
    if (!head)
      return head;
    fakeHead->next = head;
    ListNode *p = head->next;
    --k; int K = k; ListNode *pp = head;
    while (K-- && pp->next) { pp = pp->next; }
    if (K >= 0) return pp;
    while (p && k--) {
      ListNode *first = fakeHead->next;
      ListNode *pNext = p->next;
      fakeHead->next = p;
      p->next = first;
      p = pNext;
    }
    head->next = p;

    return head;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *fakeHead = new ListNode(0);
    ListNode *p = reverse(head, fakeHead, k);
    ListNode *newHead = fakeHead->next;
    while (p && p->next) { ListNode *tail = reverse(p->next, fakeHead, k); p->next = fakeHead->next; p = tail; }

    return newHead;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  for (int i = 2; i <= 2; ++i) {
    ListNode *node = new ListNode(i);
    p->next = node;
    p = p->next;
  }

  Solution s;
  ListNode *result = s.reverseKGroup(head, 2);
  while (result) {
    printf("%d->", result->val);
    result = result->next;
  }
  puts("");

  return 0;
}

