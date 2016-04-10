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
  vector<int> singleNumber(vector<int>& nums)
  {
    int xor_result = std::accumulate(nums.begin(), nums.end(), 0,
                                     [](const int i, const int result)
                                     {
                                       return i ^ result;
                                     });
    int i = 1;
    while ((xor_result & i) != i)
    {
      i  =  1 << i;
    }
    int a = 0, b = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      if ((*it & i) == i )
      {
        a ^= *it;
      }
      else
      {
        b ^= *it;
      }
    }
    return {a, b};
  }
};

int main()
{
  vector<int> vec = {1, 2, 1, 3, 2, 5};
  Solution s;
  vector<int> result = s.singleNumber(vec);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
