/*
 * author: yuandx
 * create: 2015-11-21
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
  ListNode* swapPairs(ListNode* head)
  {
    ListNode tmp(0);
    tmp.next = head;
    head = &tmp;
    ListNode* prev = head;
    while (prev != NULL)
    {
      if (prev->next != NULL && prev->next->next != NULL)
      {
        ListNode* tail = prev->next != NULL && prev->next->next != NULL ?
        prev->next->next->next : NULL;
        ListNode* cur = prev->next, *next = prev->next->next;
        prev->next = next;
        next->next = cur;
        cur->next = tail;
      }
      prev = prev->next != NULL ? prev->next->next : NULL;
    }
    return head->next;
  }
};

int main()
{

  return 0;
}
