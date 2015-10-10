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
  bool isPalindrome(int x)
  {
    long long x1 = x, y1 = 0;
    if (x < 0)
      return false;
    while (x != 0)
    {
      y1 = y1 * 10 + x % 10;
      x /= 10;
    }
    return y1 == x1;
  }
};
int main()
{

  return 0;
}
