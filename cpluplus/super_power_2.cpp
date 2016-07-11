/*
 * author: yuandx
 * create: 2016-07-10
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
  int Remain10(int rem)
  {
    int cur = (rem * rem) % 1337;
    int four = cur * cur % 1337;
    int eight = four * four % 1337;
    return eight * cur % 1337;
  }
  int superPow(int a, vector<int>& b)
  {
    a = a % 1337;
    if (a == 0)
      return 0;
    int remain = 1;
    for (auto it = b.begin(); it != b.end(); ++it)
    {
      int cur = 1;
      for (int i = 0; i < *it; i++)
      {
        cur = (cur * a) %  1337;
      }
      remain = (Remain10(remain) * cur) % 1337;
    }
    return remain;
  }
};

int main()
{
  Solution sol;
  vector<int> v = {3};
  cout << sol.superPow(2, v) << endl;
  return 0;
}
