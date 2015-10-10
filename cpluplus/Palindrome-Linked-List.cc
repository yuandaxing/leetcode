#include <iostream>
using std::cout;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode* Reverse(ListNode* h)
  {
    ListNode *newH = NULL;
    while (h != NULL)
    {
      ListNode* next = h->next;
      h->next = newH;
      newH = h;
      h = next;
    }
    return newH;
  }
  int Len(ListNode* h)
  {
    int count = 0;
    while (h != NULL)
    {
      count += 1;
      h = h->next;
    }
    return count;
  }
  bool isPalindrome(ListNode* head)
  {
    int len = Len(head) / 2;
    ListNode* half = NULL, **p = &head;
    for (int i = 0; i != len; i++)
    {
      p = &(*p)->next;
    }
    half = *p;
    *p = NULL;
    half = Reverse(half);

    ListNode* h1 = head, *h2 = half;
    bool ret = true;
    while (h1 != NULL && h2 != NULL)
    {
      if (h1->val != h2->val)
      {
        ret = false;
        break;
      }
      h1 = h1->next;
      h2 = h2->next;
    }
    *p = Reverse(half);
    return ret;
  }
};
