/*
 * author: yuandx
 * create: 2016-04-23
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <deque>
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
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
  std::list<int> result_;
  std::list<const NestedInteger*> integers_;
  NestedIterator(vector<NestedInteger> &nestedList)
  {
    for (auto it = nestedList.begin(); it != nestedList.end(); ++it)
    {
      integers_.push_back(&(*it));
    }
  }
  void TryToFetchOne()
  {
    while (!integers_.empty())
    {
      const NestedInteger* first = integers_.front();
      integers_.pop_front;
      if (first->isInteger())
      {
        result_.push_back(first->getInteger());
        return;
      } else
      {
        const vector<NestedInteger>& cur = first->getList();
        for (auto it = cur.rbegin(); it != cur.rend(); ++it)
        {
          integers_.push_front(&(*it));
        }
      }
    }
  }
  int next() {
    int val = result_.front();
    result_.pop_front();
    return val;
  }

    bool hasNext() {
      TryToFetchOne();
      return !result_.empty();
    }
};
class Solution
{
public:

};

int main()
{
  return 0;
}
