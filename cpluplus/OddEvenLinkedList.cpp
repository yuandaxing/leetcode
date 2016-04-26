/*
 * author: yuandx
 * create: 2016-04-24
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
  ListNode* oddEvenList(ListNode* head)
  {
    ListNode* even = NULL;
    ListNode **p1 = &head, **p2 = &even;
    int count = 0;
    while (*p1 != NULL)
    {
      count++;
      if ((count & 1) == 0)
      {
        *p2 = *p1;
        *p1 = (*p1)->next;
        p2 = &((*p2)->next);
        *p2 = NULL;
      }
      else
      {
        p1 = &(*p1)->next;
      }
    }
    *p1 = even;
    return head;
  }
};

int main()
{

  return 0;
}
