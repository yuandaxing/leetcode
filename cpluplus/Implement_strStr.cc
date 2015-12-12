/*
 * author: yuandx
 * create: 2015-12-12
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
  int strStr(string haystack, string needle)
  {
    int i = 0;
    for (; i <= static_cast<int>(haystack.size() - needle.size()); i++)
    {
      size_t j = 0;
      for (; j != needle.size(); j++)
      {
        if (haystack[i+j] != needle[j])
        {
          break;
        }
      }
      if (j >= needle.size())
        return i;
    }
    return haystack.empty() && needle.empty() ? 0 : -1;
  }
};

int main()
{

  return 0;
}
