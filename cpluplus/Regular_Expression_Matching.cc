/*
 * author: yuandx
 * create: 2015-11-14
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
  bool MatchReg(string s, size_t i, string p, size_t j)
  {
    if ( i == s.size())
    {
      return j == p.size() || (j+1 < p.size() && p[j+1] == '*' &&
                               MatchReg(s, i, p, j+2));
    }
    else if (j == p.size())
    {
      return false;
    }

    if (j+1 < p.size() && p[j+1] == '*')
    {
      return ((p[j] == s[i] || p[j] == '.') && MatchReg(s, i+1, p, j)) ||
        MatchReg(s, i, p, j+2);
    } else
    {
      return (p[j] == s[i] || p[j] == '.') && MatchReg(s, i+1, p, j+1);
    }
  }
  bool isNormalize(size_t i, string p, size_t& result)
  {
    bool find = false;
    while (i < p.size() && i+1 < p.size() && p[i+1]=='*')
    {
      if (p[i] == '.')
        find = true;
      i += 2;
    }
    result = i;
    return find;
  }
  string Normalize(string pattern)
  {
    size_t i = 0, result = 0;
    string ret;
    while (i < pattern.size())
    {
      if (i+1 < pattern.size() && pattern[i+1] == '*' &&
          isNormalize(i, pattern, result))
      {
        ret.push_back('.');
        ret.push_back('*');
        i = result;
      } else
      {
        ret.push_back(pattern[i]);
        i++;
      }
    }
    return ret;
  }
  bool isMatch(string s, string p)
  {
    string pattern = Normalize(p);
    return MatchReg(s, 0, pattern, 0);
  }
};

int main()
{

  return 0;
}
