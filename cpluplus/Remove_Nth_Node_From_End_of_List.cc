/*
 * author: yuandx
 * create: 2015-11-17
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    ListNode *ln = NULL, *tail = head, *cur = head;
    for (int i = 0; i < n; i++)
    {
      tail = tail->next;
    }
    for (; tail != NULL; tail = tail->next)
    {
      ln = cur;
      cur = cur->next;
    }
    if (ln == NULL)
    {
      head = head->next;
    }
    else
    {
      ln->next = cur->next;
    }
    cur->next = NULL;
    return head;
  }
};

int main()
{

  return 0;
}
