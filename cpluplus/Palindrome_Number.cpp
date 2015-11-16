/*
 * author: yuandx
 * create: 2015-11-10
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
  bool isPalindrome(int x)
  {
    if (x < 0)
      return false;
    int count = 0;
    int tmp = x;
    while (tmp != 0)
    {
      count++;
      tmp /= 10;
    }
    int v_10 = 1;
    for (int i = 1; i < count; i++)
    {
      v_10 *= 10;
    }
    while (x != 0)
    {
      int right = x / v_10;
      int left = x % 10;
      if (right != left)
      {
        return false;
      }
      x %= v_10;
      x /= 10;
      v_10 /= 100;
    }
    return true;
  }
};

int main()
{

  return 0;
}
