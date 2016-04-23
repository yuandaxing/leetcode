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
  string reverseString(string s)
  {
    if (s.size() < 2u)
      return s;
    int left = 0, right = s.size() - 1;
    for (; left < right; left++, right--)
    {
      std::swap(s[left], s[right]);
    }
    return s;
  }
};

int main()
{

  return 0;
}
