/*
 * author: yuandx
 * create: 2016-05-23
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
  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    vector<vector<int>> result, tmp;
    result.push_back(vector<int>());
    map<int, int> v_freq;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      v_freq[*it] += 1;
    }

    for (auto it = v_freq.begin(); it != v_freq.end(); ++it)
    {
      vector<int> v_k;
      for (int i = 0; i <= it->second; ++i)
      {
        for (auto it1 = result.begin(); it1 != result.end(); ++it1)
        {
          vector<int> cur(*it1);
          cur.insert(cur.end(), v_k.begin(), v_k.end());
          tmp.push_back(cur);
        }
        v_k.push_back(it->first);
      }
      tmp.swap(result);
      tmp.clear();
    }
    return result;
  }
};

int main()
{

  return 0;
}
