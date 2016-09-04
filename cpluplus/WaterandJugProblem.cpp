/*
 * author: yuandx
 * create: 2016-07-09
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
#include <queue>

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
using std::deque;

struct State
{
  int s1, s2;
  State(int x, int y):
    s1(x), s2(y)
  {}
};
struct Compare
{
  bool operator()(const State& s1, const State& s2)
  {
    if(s1.s1 != s2.s1)
    {
      return s1.s1 - s2.s1 < 0;
    }
    return s1.s2 - s2.s2 < 0;
  }
};
auto C1 = [](const State& s1, const State& s2)
{
  if(s1.s1 != s2.s1)
  {
    return s1.s1 - s2.s1 < 0;
  }
  return s1.s2 - s2.s2 < 0;
};
class Solution
{
public:
  Solution():
    s1(C1)
  {}
  int x_, y_;
  set<State, Compare> ss_;
  set<State, decltype(C1)> s1;
  std::deque<State> queue_;
  void Insert(const State& s)
  {
    if (ss_.find(s) == ss_.end())
    {
      ss_.insert(s);
      queue_.push_back(s);
      //cout << "(" << s.s1 << "," << s.s2 << ") " ;
    }
  }
  void MoveNext(const State& s)
  {
    int x1 = s.s1, x2 = s.s2;
    Insert(State(x1, 0));
    Insert(State(0, x2));
    if (x1 + x2 < x_)
    {
      Insert(State(x1+x2, 0));
    }
    else
    {
      Insert(State(x_, x1+x2-x_));
      Insert(State(0, x1+x2-x_));
      Insert(State(x_, 0));
    }

    if (x1+x2 < y_)
    {
      Insert(State(0, x1+x2));
    }
    else
    {
      Insert(State(x1+x2-y_, y_));
      Insert(State(x1+x2-y_, 0));
      Insert(State(0, y_));
    }
  }
  bool canMeasureWater(int x, int y, int z)
  {
    int temp_x = x, temp_y = y;
    x_ = std::min(temp_x, temp_y), y_ = std::max(temp_x, temp_y);
    if (x + y < z)
    {
      return false;
    }
    queue_.push_back(State(0, 0));
    ss_.insert(State(0, 0));
    while (!queue_.empty())
    {
      State cur = queue_.front();
      queue_.pop_front();
      if (cur.s1 + cur.s2 == z)
      {
        return true;
      }
      MoveNext(cur);
      MoveNext(State(cur.s1, y_));
      MoveNext(State(x_, cur.s2));
    }
    return false;
  }
};

int main()
{
  Solution sol;
  cout << sol.canMeasureWater(104579, 104593, 12444) << endl;
  return 0;
}
