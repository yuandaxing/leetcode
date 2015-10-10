/*
 * author: yuandx
 * create: 2015-09-30
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <string>
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    size_t max = 0, start = 0, end = 0;
    char mark[128] = {0};
    for (; end != s.size(); ++end)
    {
      mark[s[end]] += 1;
      while (mark[s[end]] >= 2)
      {
        mark[s[start]] -= 1;
        start += 1;
      }
      max = std::max(max, end - start + 1);
    }
    return max;
  }
};
int main()
{

  return 0;
}
