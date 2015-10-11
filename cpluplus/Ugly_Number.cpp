/*
 * author: yuandx
 * create: 2015-10-10
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
#include <stdlib.h>
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
  int RemoveFactor(int num, int factor)
  {
    while (num / factor * factor == num)
    {
      num /= factor;
    }
    return num;
  }
  bool isUgly(int num)
  {
    if (num <= 0)
      return false;
    num = RemoveFactor(num, 2);
    num = RemoveFactor(num, 3);
    num = RemoveFactor(num, 5);
    return num == 1;
  }
};

int main()
{
  Solution sol;
  cout << sol.isUgly(4) << endl;
  cout << sol.isUgly(7) << endl;
  return 0;
}
