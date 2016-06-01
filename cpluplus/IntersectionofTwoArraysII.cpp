/*
 * author: yuandx
 * create: 2016-06-01
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
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
  {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    vector<int> result;
    for (auto iter1 = nums1.begin(), iter2 = nums2.begin(); iter1 != nums1.end() && iter2 != nums2.end(); )
    {
      int v1 = *iter1, v2 = *iter2;
      if (v1 < v2)
      {
        ++iter1;
      } else if (v1 > v2)
      {
        ++iter2;
      } else
      {
        result.push_back(v1);
        ++iter1;
        ++iter2;
      }
    }
    return result;
  }
};

int main()
{

  return 0;
}
