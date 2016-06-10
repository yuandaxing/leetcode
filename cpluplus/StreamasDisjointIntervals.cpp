/*
 * author: yuandx
 * create: 2016-06-08
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
#include <list>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
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

struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0)
  {}
  Interval(int s, int e) : start(s), end(e)
  {}
};
class SummaryRanges
{
public:
  list<Interval> interval_;
  /** Initialize your data structure here. */
  SummaryRanges()
  {
  }

  void TryMerge(list<Interval>::iterator it)
  {
    if (it == interval_.end())
    {
      return ;
    }
    auto it1 = it;
    ++it1;
    if (it1 != interval_.end())
    {
      if (it->start <= it1->start && it->end + 1 >= it1->start)
      {
        it->end = std::max(it->end, it1->end);
        interval_.erase(it1);
      }
    }
  }
  void addNum(int val)
  {
    auto it = std::find_if(interval_.begin(), interval_.end(), [&val](const Interval& i) { return i.start >= val; });
    interval_.insert(it, {val, val});
    --it;
    TryMerge(it);
    if (it != interval_.begin())
    {
      --it;
      TryMerge(it);
    }
  }

  vector<Interval> getIntervals()
  {
    return vector<Interval>(interval_.begin(), interval_.end());
  }
};


int main()
{
  vector<int> streams = {1, 3, 7, 2, 6,};
  SummaryRanges SR;
  for (auto it = streams.begin(); it != streams.end(); ++it)
  {
    SR.addNum(*it);
    vector<Interval> is = SR.getIntervals();
    for (auto it = is.begin(); it != is.end(); ++it)
    {
      cout << "(" << it->start << ", " << it->end << ")";
    }
    cout << endl;
  }

  return 0;
}
