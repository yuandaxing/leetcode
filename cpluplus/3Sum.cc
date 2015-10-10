/*
 * author: yuandx
 * create: 2015-10-03
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
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
using std::string;
using std::for_each;

struct Triple
{
  int x, y, z;
  Triple(int x1, int y1, int z1): x(x1), y(y1), z(z1)
  {
  }
};
bool operator<(const Triple& lhs, const Triple& rhs)
{
  if (lhs.x != rhs.x)
    return lhs.x - rhs.x > 0;
  if (lhs.y != rhs.y)
    return lhs.y - rhs.y > 0;
  if (lhs.z != rhs.z)
    return lhs.z - rhs.z > 0;
  return false;
}

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    std::multiset<int> nums_to_idx;
    std::set<Triple> ret_set;
    for (size_t i = 0; i != nums.size(); i++)
    {
      nums_to_idx.insert(nums[i]);
    }
    for (auto it = nums_to_idx.begin(); it != nums_to_idx.end(); ++it)
    {
      auto it1 = it, it2 = --(nums_to_idx.end());
      ++it1;
      while (it1 != nums_to_idx.end() && it1 != it2)
      {
        int sum = *it + *it1 + *it2;
        if (sum > 0)
          --it2;
        else if (sum < 0)
          ++it1;
        else
        {
          ret_set.insert(Triple(*it, *it1, *it2));
          ++it1;
        }
      }
    }
    vector<vector<int>> ret;
    std::for_each(ret_set.begin(), ret_set.end(), [&ret](const Triple& e)
                  {
                    ret.push_back({e.x, e.y, e.z});
                  });
    return ret;
  }
};
int main()
{
  Solution sol = Solution();
  vector<int> input = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
  for (auto & e : sol.threeSum(input))
  {
    cout << e[0] << " " << e[1] << " " << e[2] << "\t";
  }
  cout << endl;
  return 0;
}
