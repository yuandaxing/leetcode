/*
 * author: yuandx
 * create: 2015-10-10
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
  void moveZeroes(vector<int>& nums)
  {
    size_t beg = 0;
    for (size_t i = 0; i != nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        nums[beg++] = nums[i];
      }
    }
    fill(nums.begin() + beg, nums.end(), 0);
  }
};
int main()
{

  return 0;
}
