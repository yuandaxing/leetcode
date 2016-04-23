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

class Solution
{
public:
  int lengthOfLIS(vector<int>& nums)
  {
    vector<int> lowest;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      auto it1 = lower_bound(lowest.begin(), lowest.end(), *it);
      if (it1 != lowest.end())
        *it1 = *it;
      else
        lowest.push_back(*it);
    }
    return lowest.size();
  }
};

int main()
{

  return 0;
}
