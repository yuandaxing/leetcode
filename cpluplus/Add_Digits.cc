/*
 * author: yuandx
 * create: 2015-10-10
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
  int addDigits(int num)
  {
    while (num >= 10)
    {
      int cur = 0;
      while (num != 0)
      {
        cur += num % 10;
        num /= 10;
      }
      num = cur;
    }
    return num;
  }
};
int main()
{

  return 0;
}
