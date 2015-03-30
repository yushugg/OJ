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
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode *fakeHead = new ListNode(0);
    fakeHead->next = head;

    ListNode *endPrev = fakeHead;
    int count = 0;
    while (endPrev->next)
    {
      ++count;
      endPrev = endPrev->next;
    }

    if (count < 2)
      return head;
    k %= count;
    if (!k)
      return head;
    ListNode *rotatePrev = fakeHead;
    int i = 0;
    while (i < count - k)
    {
      ++i;
      rotatePrev = rotatePrev->next;
    }

    // Rotate
    fakeHead->next = rotatePrev->next;
    endPrev->next = head;
    rotatePrev->next = NULL;

    return fakeHead->next;
  }
};
