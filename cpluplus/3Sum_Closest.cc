/*
 * author: yuandx
 * create: 2015-11-16
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
  int threeSumClosest(vector<int>& nums, int target)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int size = static_cast<int>(nums.size());
    if (size < 3)
    {
      return target;
    }
    int best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < size; i++)
    {
      if (i > 0 && nums[i-1] == nums[i])
      {
        continue;
      }
      int j = i + 1, k = size - 1;
      while (j < k)
      {
        if (j > i+1 && nums[j] == nums[j-1])
        {
          j++;
          continue;
        }
        int value = nums[i] + nums[j] + nums[k];
        if (abs(best-target) > abs(value - target))
        {
          best = value;
        }
        if (value < target)
        {
          j++;
        }
        else if (value >target)
        {
          k--;
        }
        else
        {
          return best;
        }
      }
    }
    return best;
  }
};

int main()
{

  return 0;
}
