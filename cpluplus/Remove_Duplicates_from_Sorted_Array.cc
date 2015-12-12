/*
 * author: yuandx
 * create: 2015-12-12
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
  int removeDuplicates(vector<int>& nums)
  {
    size_t j = 0;
    for (size_t i = 0; i != nums.size(); i++)
    {
      if (i > 0 && nums[i-1] == nums[i])
        continue;
      nums[j++] = nums[i];
    }
    nums.resize(j);
    return j;
  }
};

int main()
{

  return 0;
}
