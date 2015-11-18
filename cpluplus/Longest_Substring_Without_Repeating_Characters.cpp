/*
 * author: yuandx
 * create: 2015-11-05
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
  int lengthOfLongestSubstring(string s)
  {
    int max_length = 0, start = 0;
    char mark[128] = {0};
    for (size_t i = 0; i != s.size(); i++)
    {
      mark[s[i]] += 1;
      while (mark[s[i]] >= 2)
      {
        mark[s[start]] -= 1;
        start++;
      }
      max_length = std::max(max_length, static_cast<int>(i) - start + 1);
    }
    return max_length;
  }
};

int main()
{

  return 0;
}
