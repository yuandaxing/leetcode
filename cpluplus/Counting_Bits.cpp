/*
 * author: yuandx
 * create: 2016-04-24
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
  /*
    0 = 0
    1 = 1
    2 = 1
    3 = 2
    4 = 1
    5 = 2
    6 = 2
    7 = 3
    8 = 1
    9 = 2
    10 = 2
   */
  vector<int> countBits(int num)
  {
    vector<int> result = {0};
    for (int i = 1; i <= num && result.size() <= static_cast<size_t>(num); i <<= 1)
    {
      for (int k = 0; k < i && result.size() <= static_cast<size_t>(num); k++)
      {
        result.push_back(1 + result[k]);
      }
    }
    return result;
  }
};
void Print(const vector<int>& v)
{
  for (int i = 0; i != v.size(); i++)
    std::cout << v[i] << "\t" ;
  std::cout << std::endl;
}
int main()
{
  Solution sol;
  Print(sol.countBits(0));
  Print(sol.countBits(1));
  Print(sol.countBits(2));
  Print(sol.countBits(3));
  Print(sol.countBits(4));
  return 0;
}
