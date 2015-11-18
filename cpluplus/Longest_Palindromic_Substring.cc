/*
 * author: yuandx
 * create: 2015-09-30
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
/*
 *
 */
class Solution
{
public:
  void Expand(string& s, int i, int j, string& max)
  {
    int size = static_cast<int>(s.size());
    while (i >= 0 && j < size && s[i] == s[j])
    {
      i--;
      j++;
    }
    if (j - i - 1 > static_cast<int>(max.size()))
    {
      max = s.substr(i + 1, j - i - 1);
    }
  }
  string longestPalindrome(string s)
  {
    string ret;
    for (int i = 0; i != static_cast<int>(s.size()); i++)
    {
      Expand(s, i, i, ret);
      Expand(s, i, i+1, ret);
    }
    return ret;
  }
};
int main()
{

  return 0;
}
