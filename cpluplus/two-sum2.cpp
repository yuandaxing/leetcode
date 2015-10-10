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

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    vector<int> ret;
    std::multimap<int, int> v_2_i;
    for (size_t i = 0; i != nums.size(); i++)
    {
      v_2_i.insert({nums[i], i+1});
    }
    if (v_2_i.size() == 0u)
    {
      return ret;
    }
    auto beg = v_2_i.begin(), end = --v_2_i.end();
    while (beg != end)
    {
      int sum = beg->first + end->first;
      if (sum > target)
      {
        --end;
      }
      else if (sum < target)
      {
        ++beg;
      }
      else
      {
        ret.push_back(beg->second);
        ret.push_back(end->second);
        break;
      }
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};
int main()
{

  return 0;
}
