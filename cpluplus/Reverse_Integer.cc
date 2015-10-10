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
  int reverse(int x)
  {
    long long int x1 = x, result = 0;
    bool sign = x1 > 0 ? true : false;
    x1 = abs(x1);
    for (; x1 != 0 ; x1 /= 10)
    {
      result = result * 10 + x1 % 10;
    }
    result = result > INT_MAX ? 0 : result;
    result = sign ? result : -result;
    return result;
  }
};
int main()
{

  return 0;
}
