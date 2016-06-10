/*
 * author: yuandx
 * create: 2016-06-08
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
  bool IsIn(pair<int, int>& p1, pair<int,int>& p2)
  {
    return p2.first > p1.first && p2.second > p1.second;
  }
  int maxEnvelopes(vector<pair<int, int>>& envelopes)
  {
    int size = static_cast<int>(envelopes.size());
    vector<int> v1(size, 0);
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (IsIn(envelopes[j], envelopes[i]))
        {
          v1[i] += 1;
        }
      }
    }
    auto it = std::max_element(v1.begin(), v1.end());
    return it == v1.end() ? 0 : *it;
  }
};

int main()
{

  return 0;
}
