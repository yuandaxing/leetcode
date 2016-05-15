/*
 * author: yuandx
 * create: 2016-05-15
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
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int, int> value_freq;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      value_freq[*it] += 1;
    }
    vector<std::pair<int, int>> tmp(value_freq.begin(), value_freq.end());
    std::sort(tmp.begin(), tmp.end(), [](std::pair<int, int>& left,
                                         std::pair<int, int>& right)
              { return left.second > right.second;});
    vector<int> result;
    for (int i = 0; i < k && i < static_cast<int>(tmp.size()); i++)
    {
      result.push_back(tmp[i].first);
    }
    return result;
  }
};

int main()
{

  return 0;
}
