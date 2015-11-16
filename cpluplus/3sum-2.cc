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
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int size = static_cast<int>(nums.size());
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
        if (value < 0)
        {
          j++;
        }
        else if (value > 0)
        {
          k--;
        }
        else
        {
          result.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
        }
      }
    }
    return result;
  }
};

int main()
{

  return 0;
}
