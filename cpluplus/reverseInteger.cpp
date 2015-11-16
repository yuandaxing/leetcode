/*
 * author: yuandx
 * create: 2015-11-06
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
  int reverse(int x)
  {
    int abs_v = abs(x);
    bool negative = x < 0;
    int rev = 0;
    while (abs_v != 0)
    {
      int prev = rev;
      rev = rev * 10 +  abs_v % 10;
      if (prev != (rev / 10))
      {
        rev = 0;
        break;
      }
      abs_v /= 10;
    }
    return negative ? -rev : rev;
  }
};

int main()
{

  return 0;
}
