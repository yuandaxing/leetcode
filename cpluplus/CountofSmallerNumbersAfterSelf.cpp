/*
 * author: yuandx
 * create: 2016-06-03
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
  vector<int> countSmaller(vector<int>& nums)
  {
    std::reverse(nums.begin(), nums.end());
    vector<int> result;
    vector<int> tmp;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      auto pos = std::lower_bound(tmp.begin(), tmp.end(), *it);
      result.push_back(pos - tmp.begin());
      tmp.insert(pos, *it);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> v = {-1, -1};
  vector<int> result = sol.countSmaller(v);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << " " ;
  }
  cout << endl;
  return 0;
}
