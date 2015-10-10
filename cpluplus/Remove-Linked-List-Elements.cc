#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode* removeElements(ListNode* head, int val)
  {
    ListNode **p = &head;
    while (*p != NULL)
    {
      if ((*p)->val == val)
      {
        ListNode* tmp = *p;
        *p = tmp->next;
        delete tmp;
      }
      else
      {
        p = &((*p)->next);
      }
    }
    return head;
  }
};
