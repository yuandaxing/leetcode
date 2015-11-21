/*
 * author: yuandx
 * create: 2015-11-19
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
#include <list>
#include <unordered_set>
using std::list;
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

void Print(ListNode* ln)
{
  while (ln != NULL)
  {
    cout << " " << ln->val;
    ln = ln->next;
  }
  cout << endl;
}
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
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    vector<ListNode*> l1(lists.begin(), lists.end());
    for (size_t i = 1; i < l1.size(); i+=2)
    {
      l1.push_back(mergeTwoLists(l1[i], l1[i-1]));
    }
    if (l1.empty())
      return NULL;
    else
      return l1.back();
  }
};

int main()
{
  ListNode ln(1);
  vector<ListNode*> tmp = {&ln};
  Solution sol;
  Print(sol.mergeKLists(tmp));
  return 0;
}
