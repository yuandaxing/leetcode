/*
 * author: yuandx
 * create: 2015-10-03
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;

class Solution
{
public:
  int myAtoi(string str)
  {
    int result = 0, idx = 0, size = static_cast<int>(str.size());
    bool positive = true;
    while (idx < size && str[idx] == ' ') idx++;
    if (idx >= size)
      return result;
    if (str[idx] == '-')
    {
      idx++;
      positive = false;
    }
    else if (str[idx] == '+')
      idx++;

    for (; idx < size && str[idx] >= '0' && str[idx] <= '9'; idx++)
    {
      long long cur = result * 10ll + str[idx] - '0';
      if (cur > INT_MAX)
      {
        return positive ? INT_MAX : INT_MIN;
      }
      result = cur;
    }
    result = positive ? result : -result;
    return result;
  }
};
int main()
{
  string str = "    10522545459";
  Solution sol = Solution();
  cout << sol.myAtoi(str);
  cout << endl;
  return 0;
}
