/*
 * author: yuandx
 * create: 2015-10-03
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
using std::for_each;
class Solution
{
public:
  string longestCommonPrefix(vector<string>& strs)
  {
    if (strs.size() == 0u)
      return "";
    string prefix = strs[0];
    for (std::size_t i = 1; i != strs.size(); i++)
    {
      std::size_t j = 0;
      for (; j != prefix.size() && j != strs[i].size(); j++)
      {
        if (prefix[j] != strs[i][j])
          break;
      }
      prefix.resize(j);
    }
    return prefix;
  }
};
int main()
{

  return 0;
}
