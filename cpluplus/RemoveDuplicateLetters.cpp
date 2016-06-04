/*
 * author: yuandx
 * create: 2016-06-03
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
#include <list>
#include <unordered_map>
#include <unordered_set>
using std::list;
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
  string removeDuplicateLetters(string s)
  {
    if (s.empty())
    {
      return s;
    }
    list<char> result;
    std::reverse(s.begin(), s.end());
    result.push_back(s[0]);
    for (size_t i = 1; i < s.size(); i++)
    {
      auto it = find(result.begin(), result.end(), s[i]);
      if (it == result.end())
      {
        result.push_back(s[i]);
        continue;
      }
      char back = result.back();
      if (back > s[i])
      {
        result.erase(it);
        result.push_back(s[i]);
      }
    }
    string ret(result.begin(), result.end());
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main()
{
  Solution sol;
  cout << sol.removeDuplicateLetters("bcabc") << endl;
  return 0;
}
