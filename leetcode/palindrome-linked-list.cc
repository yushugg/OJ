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
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *mid;
    if (fast) mid = slow->next;
    else mid = slow;

    // Reverse link list
    ListNode *x = mid, *y = mid->next, *z;
    while (y) {
      z = y->next;
      y->next = x;
      x = y;
      y = z;
    }
    mid->next = NULL;

    // Compare
    while (x) {
      if (head->val != x->val) return false;
      x = x->next;
      head = head->next;
    }
    return true;
  }
};
