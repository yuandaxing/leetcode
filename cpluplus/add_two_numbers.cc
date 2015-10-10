/*
 * author: yuandx
 * create: 2015-09-29
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode* l3 = NULL, *last = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
      int sum = 0;
      if (l1 != NULL)
      {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL)
      {
        sum += l2->val;
        l2 = l2->next;
      }
      sum += carry;
      if (last == NULL)
      {
        l3 = last = new ListNode(sum % 10);
      }
      else
      {
        last->next = new ListNode(sum % 10);
        last = last->next;
      }
      carry = sum / 10;
    }
    return l3;
  }
};

int main()
{

  return 0;
}
