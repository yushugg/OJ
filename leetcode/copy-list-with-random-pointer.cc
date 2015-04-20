/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <unordered_map>

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return head;
    std::unordered_map<RandomListNode*, RandomListNode*> map;
    RandomListNode *newHead = new RandomListNode(head->label);
    map.insert(std::make_pair(head, newHead));
    RandomListNode *p = head->next, *pn = newHead;
    while (p) {
      RandomListNode *node = new RandomListNode(p->label);
      map.insert(std::make_pair(p, node));
      pn->next = node;
      p = p->next;
      pn = pn->next;
    }

    // Assign random pointers
    p = head; pn = newHead;
    while (p) {
      pn->random = map[p->random];
      p = p->next;
      pn = pn->next;
    }

    return newHead;
  }
};
