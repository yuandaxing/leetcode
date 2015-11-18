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
  int longestRound(string& s, int i, int j)
  {
    for (; i >=0 && j < static_cast<int>(s.size()) && s[i] == s[j]; i--, j++);
    return j-i-1;
  }
  string longestPalindrome(string s)
  {
    int max = 0;
    string max_string = "";
    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
      int cur = longestRound(s, i, i);
      if (cur > max)
      {
        max_string = s.substr(i - cur/2, cur);
        max = cur;
      }

      cur = longestRound(s, i, i+1);
      if (cur > max)
      {
        max_string = s.substr(i - (cur/2-1), cur);
        max = cur;
      }
    }
    return max_string;
  }
};

int main()
{
  Solution sol;
  cout << sol.longestPalindrome("bb");
  return 0;
}
