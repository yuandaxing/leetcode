/*
 * author: yuandx
 * create: 2016-07-09
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
  bool isPerfectSquare(int num)
  {
    if (num < 0)
    {
      return false;
    }
    long long left = 0, right = num;
    while (left <= right)
    {
      long long mid = (left + (long long)right) / 2;
      long long v = mid * mid;
      if (v == num)
      {
        return true;
      }
      else if (v > num)
      {
        right = mid - 1;
      } else
      {
        left = mid + 1;
      }
    }
    return false;
  }
};
int main()
{

  return 0;
}
