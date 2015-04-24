#include <vector>
#include <cstdio>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* merge(ListNode *l1, ListNode *l2, ListNode *fakeHead) {
    fakeHead->next = NULL;
    ListNode *p = fakeHead;
    while (l1 && l2) {
      if (l1->val < l2->val) { p->next = l1; l1 = l1->next; }
      else { p->next = l2; l2 = l2->next; }
      p = p->next;
    }
    while (l1) { p->next = l1; l1 = l1->next; p = p->next; }
    while (l2) { p->next = l2; l2 = l2->next; p = p->next; }

    return fakeHead->next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size = lists.size();
    if (!size) return NULL;
    ListNode *fakeHead = new ListNode(0);
    while (size > 1) {
      int count = 0;
      for (int i = 0; i < size; i += 2) {
        if (i + 1 < size) lists[count++] = merge(lists[i], lists[i + 1], fakeHead);
        else lists[count++] = lists[i];
      }
      size = count;
    }

    return lists[0];
  }

  ListNode* constructList(int size) {
    ListNode *fakeHead = new ListNode(0);
    ListNode *p = fakeHead;
    for (int i = 0; i < size; ++i) {
      int val;
      scanf("%d", &val);
      p->next = new ListNode(val);
      p = p->next;
    }
    
    return fakeHead->next;
  }

  void printList(ListNode *list) {
    while (list) {
      printf("%d->", list->val);
      list = list->next;
    }
    puts("");
  }
};

int main() {
  freopen("in.txt", "r", stdin);
  int total;
  scanf("%d", &total);
  vector<ListNode*> lists;
  Solution solution;
  for (int i = 0; i < total; ++i) {
    int size;
    scanf("%d", &size);
    ListNode *head = solution.constructList(size);
    lists.push_back(head);
  }

  solution.printList(solution.mergeKLists(lists));

  return 0;
}

