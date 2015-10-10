/*
 * author: yuandx
 * create: 2015-09-28
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
class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    vector<pair<int, int>> v_2_idx;
    for (std::size_t i = 0; i != nums.size(); i++)
    {
      v_2_idx.push_back({nums[i], i+1});
    }
    sort(v_2_idx.begin(), v_2_idx.end());
    vector<int> result;
    int left = 0, right = static_cast<int>(v_2_idx.size()) - 1;
    while (left < right)
    {
      int sum = v_2_idx[left].first + v_2_idx[right].first;
      if (sum > target)
        right--;
      else if (sum < target)
        left++;
      else
      {
        result.push_back(v_2_idx[left].second);
        result.push_back(v_2_idx[right].second);
        break;
      }
    }
    sort(result.begin(), result.end());
    return result;
  }
};
int main()
{

  return 0;
}
