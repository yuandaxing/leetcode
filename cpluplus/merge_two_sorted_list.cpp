/*
 * author: yuandx
 * create: 2015-11-18
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
      ListNode tmp(0);
      ListNode* head = &tmp, *prev = &tmp;
      while (l1 != NULL && l2 != NULL)
      {
        ListNode* cur = NULL;
        if (l1->val > l2->val)
        {
          cur = l2;
          l2 = l2->next;
        }
        else
        {
          cur = l1;
          l1 = l1->next;
        }
        cur->next = NULL;
        prev->next = cur;
        prev = cur;
      }
      if (l1 != NULL)
      {
        prev->next = l1;
      }
      else
      {
        prev->next = l2;
      }
      head = head->next;
      return head;
    }
};

int main()
{

  return 0;
}
