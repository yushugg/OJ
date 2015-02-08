#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // Calculate length of two lists
    int lenA = 0, lenB = 0;
    ListNode* pa = headA;
    ListNode* pb = headB;

    while (pa)
    {
      ++lenA;
      pa = pa->next;
    }

    while (pb)
    {
      ++lenB;
      pb = pb->next;
    }

    pa = headA;
    pb = headB;
    if (lenA > lenB)
    {
      for (int i = 0; i < lenA - lenB; ++i)
        pa = pa->next;
    } else {
      for (int i = 0; i < lenB - lenA; ++i)
        pb = pb->next;
    }

    while (pa && pb)
    {
      if (pa->val == pb->val)
        return pa;
      pa = pa->next;
      pb = pb->next;
    }

    return NULL;
  }
};

int main(int argc, char* argv[])
{
  int n1, n2;
  int val1[50], val2[50];
  ListNode* list1, *list2;
  ListNode* p1, *p2;

  scanf("%d", &n1);
  scanf("%d", &val1[0]);
  list1 = new ListNode(val1[0]);
  p1 = list1;
  for (int i = 1; i < n1; ++i)
  {
    scanf("%d", &val1[i]);
    ListNode* node = new ListNode(val1[i]);
    p1->next = node;
    p1 = p1->next;
  }

  scanf("%d", &n2);
  scanf("%d", &val2[0]);
  list2 = new ListNode(val2[0]);
  p2 = list2;
  for (int i = 1; i < n2; ++i)
  {
    scanf("%d", &val2[i]);
    ListNode* node = new ListNode(val2[i]);
    p2->next = node;
    p2 = p2->next;
  }

  // Intersection
  Solution s;
  ListNode* inter = s.getIntersectionNode(list1, list2);
  if (inter)
  {
    printf("Intersection node: %d\n", inter->val);
  }
  else
  {
    printf("No intersection.\n");
  }

  return 0;
}

