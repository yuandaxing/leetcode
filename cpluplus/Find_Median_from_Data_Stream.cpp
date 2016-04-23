/*
 * author: yuandx
 * create: 2016-04-23
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
class MedianFinder {
public:
  vector<int> d_;
    // Adds a number into the data structure.
  void addNum(int num)
  {
    auto it = lower_bound(d_.begin(), d_.end(), num);
    d_.insert(it, num);
  }

    // Returns the median of current data stream
  double findMedian()
  {
    if (d_.size() == 0u)
    {
      return 0;
    }
    else if (d_.size() % 2 == 0)
    {
      int v1 = d_.size() / 2 - 1, v2 = d_.size() / 2;
      return (d_[v1] + d_[v2]) / 2.0;
    }
    else
    {
      return d_[d_.size() / 2];
    }
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
