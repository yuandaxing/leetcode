/*
 * author: yuandx
 * create: 2015-11-22
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
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
  ListNode* reverse(ListNode* head)
  {
    ListNode* new_head = NULL;
    while (head != NULL)
    {
      ListNode* next = head->next;
      head->next = new_head;
      new_head = head;
      head = next;
    }
    return new_head;
  }

  ListNode* reverseKGroup(ListNode* head, int k)
  {
    ListNode tmp(0);
    tmp.next = head; head = &tmp;
    ListNode* prev = &tmp;
    while (prev != NULL)
    {
      while(count < k && cur != NULL)
      {
        ListNode* next = cur->next;
        cur->next = cur_head;
        cur_head = cur;
        count++;
        cur = next;
      }
      ListNode* next_prev = prev->next;
      prev->next = cur_head;
      if (next_prev != NULL)
      {
        next_prev->next = cur;
      }
      prev = next_prev;
    }
    return head->next;
  }
};

int main()
{

  return 0;
}
