/*
 * author: yuandx
 * create: 2015-12-09
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;
using std::ostringstream;
using std::istringstream;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;
using std::for_each;
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
  void Reverse(ListNode* h, ListNode*& tail, ListNode*& head)
  {
    ListNode *newH = NULL;
    tail = h;
    while (h != NULL)
    {
      ListNode* next = h->next;
      h->next = newH;
      newH = h;
      h = next;
    }
     head = newH;
  }

  ListNode* reverseKGroup(ListNode* head, int k)
  {
    if (k <= 1)
    {
      return head;
    }
    ListNode tmp(0);
    tmp.next = head;
    head = &tmp;
    ListNode* prev = &tmp;
    while(prev != NULL)
    {
      ListNode* next_prev = prev;
      int i = 0;
      while (next_prev != NULL && i < k)
      {
        i++;
        next_prev = next_prev->next;
      }
      ListNode* next_begin = next_prev == NULL ? NULL : next_prev->next;
      if (next_prev != NULL)
      {
        ListNode* cur_h = prev->next, *cur_t = NULL;
        next_prev->next = NULL;
        Reverse(cur_h, cur_t, cur_h);
        prev->next = cur_h, cur_t->next = next_begin;
      }
      prev = next_begin;
    }
    return head->next;

  }
};

int main()
{

  return 0;
}
