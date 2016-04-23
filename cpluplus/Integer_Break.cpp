/*
 * author: yuandx
 * create: 2016-04-23
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
    2: 1 * 1 = 1
    3: 1 * 2 = 2
    4: 2 * 2 = 4
    5: 2 * 3 = 6
    6: 3 * 3 = 9
    7: 2 * 2 * 3 = 3 * 4  = 12
    8: 3 * 3 * 2 = 18
    9: 3 * 3 * 3 = 27
    10: 3 * 3 * 4 = 36
    11: 4 * 4 * 3  3 * 3 * 3 * 2 = 54
   */
  int integerBreak(int n)
  {
    if (n < 5)
    {
      return (n / 2) * (n - n /2 );
    }

    int factori = 1;
    while (n > 4)
    {
      factori *= 3;
      n -= 3;
    }
    factori *= n;
    return factori;
  }
};

int main()
{

  return 0;
}
