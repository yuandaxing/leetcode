/*
 * author: yuandx
 * create: 2016-04-09
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
  int search(vector<int>& nums, int target)
  {
    int left = 0, right = static_cast<int>(nums.size() - 1);
    while (left <= right)
    {
      int mid = left + ((right - left) >> 1);

      if (nums[mid] == target)
        return mid;

      if (nums[mid] >= nums[left])
      {
        if (target >= nums[left] && target < nums[mid])
        {
          right = mid - 1;
        }
        else
        {
          left = mid + 1;
        }
      }
      else
      {
        if (target > nums[mid] && target <= nums[right])
        {
          left = mid + 1;
        }
        else
        {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main()
{

  return 0;
}
