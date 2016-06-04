/*
 * author: yuandx
 * create: 2016-06-04
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


static inline std::vector<std::string> Split(const std::string& s, const std::string& delim)
{
  std::vector<std::string> ret;
  size_t last = 0, index = s.find_first_of(delim, last);

  while (index != std::string::npos)
  {
    ret.push_back(s.substr(last, index - last));
    last = index + 1;
    index = s.find_first_of(delim, last);
  }

  if (index - last > 0)
  {
    ret.push_back(s.substr(last, index - last));
  }
  return ret;
}

class Solution
{
public:
  bool IsValid(vector<string>& cur, int left, int len)
  {
    if (len == 0)
      return false;
    if (len == 1)
      return cur[left] == "#";
    if (cur[left] == "#")
      return false;
    int v = 0, sharp = 0, k;
    for (k = left + 1; k < left + len; k++ )
    {
      if (cur[k] == "#")
        sharp++;
      else
        v++;
      if (v == sharp - 1)
        break;
    }
    if (k >= left + len) return false;
    return IsValid(cur, left + 1, k - left) && IsValid(cur, k+1, left + len - k -1);
  }
  bool isValidSerialization(string preorder)
  {
    vector<string> ret = Split(preorder, ",");
    return IsValid(ret, 0, ret.size());
  }
};

int main()
{
  Solution sol;
  string v = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  string v2 = "91,13,14,#,#,10";
  cout << sol.isValidSerialization(v2) << endl;
  return 0;
}
