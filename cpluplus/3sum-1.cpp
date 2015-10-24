/*
 * author: yuandx
 * create: 2015-10-23
 * email: yuandx@mvad.com
 */


#include <climits>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::ostringstream;
using std::istringstream;
using std::stringstream;
using std::vector;
using std::pair;
using std::sort;
using std::string;
using std::for_each;
using std::unordered_map;
using std::unordered_set;

struct Triple
{
  int x, y, z;
  Triple(int i, int j, int k):
    x(i), y(j), z(k)
  {}
};
class Solution
{
public:
  //[beg, end]
  vector<vector<int>> TwoSum(vector<int>& nums, int beg, int end, int sum)
  {
    vector<vector<int>> result;
    while (beg < end)
    {
      int cur = nums[beg] + nums[end];
      if (cur < sum)
      {
        beg++;
      }
      else if (cur > sum)
      {
        end--;
      }
      else
      {
        result.push_back({nums[beg], nums[end]});
        beg++;
        end--;
      }
    }
    return result;
  }
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int end = static_cast<int>(nums.size()) - 1;

    auto hasher = [](const Triple& t)
      {
        return t.x ^ t.y ^ t.z;
      };
    auto compare = [](const Triple& lhs, const Triple& rhs)
      {
        return lhs.x == rhs.x && lhs.y == rhs.y &&
        lhs.z == rhs.z;
      };
    unordered_set<Triple, decltype(hasher), decltype(compare)> uniq(1000, hasher, compare);

    for (int i = 0; i <= end; i++)
    {
      if (i > 0 && nums[i] == nums[i-1])
        continue;

      for (auto& e : TwoSum(nums, i+1, end, 0 - nums[i]))
      {
        uniq.insert(Triple(nums[i], e[0], e[1]));
      }
    }

    for (auto& e : uniq)
    {
      result.push_back({e.x, e.y, e.z});
    }
    return result;
  }
};

#include <iostream>

int main()
{
  vector<int> test = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
  sort(test.begin(), test.end());
  for (int i : test)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  Solution sol;
  for (auto& e: sol.threeSum(test))
  {
    std::cout << "(" << e[0] << " " << e[1] << " " << e[2] << ")" << " ";
  }
  std::cout << std::endl;
  return 0;
}
