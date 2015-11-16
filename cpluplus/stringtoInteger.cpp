/*
 * author: yuandx
 * create: 2015-11-09
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
  int myAtoi(string str)
  {
    size_t i = 0;
    while(i != str.size() && str[i] == ' ') i++;
    bool positive = true;
    if (i != str.size() && str[i] == '-')
    {
      positive = false;
      i++;
    } else if (i != str.size() && str[i] == '+')
    {
      positive = true;
      i++;
    }
    unsigned int value = 0;
    while (i != str.size() && str[i] >= '0' && str[i] <= '9')
    {
      unsigned int prev = value;
      value = value * 10 + str[i] - '0';
      if (value / 10 != prev)
      {
        value = INT_MAX + 1;
      }
      i++;
    }

    if (positive)
    {
      return value > INT_MAX ? INT_MAX : value;
    }
    else
    {
      return value >= INT_MAX + 1 ? INT_MIN : -static_cast<int>(value);
    }
  }
};

int main()
{

  return 0;
}
