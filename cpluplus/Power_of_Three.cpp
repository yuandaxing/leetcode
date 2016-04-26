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
    3
    6
    9 8 + 1
    12
    27 16 + 8 + 2 + 1
    81 = 64 + 16 + 1
  */
  bool isPowerOfThree(int n)
  {
    while (n > 1)
    {
      int val = n / 3;
      if (val * 3 != n)
      {
        return false;
      }
      n = val;
    }
    return n == 1;
  }
};

int main()
{

  return 0;
}
