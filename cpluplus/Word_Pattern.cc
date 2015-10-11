/*
 * author: yuandx
 * create: 2015-10-10
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

  inline std::vector<std::string> Split(const std::string& s, const std::string& delim)
  {
    std::vector<std::string> ret;
    size_t start = 0, next = 0;
    do
    {
      next = s.find_first_of(delim, start);
      ret.push_back(s.substr(start, next - start));
      start = next + 1;
    } while (next != std::string::npos);
    return ret;
  }
  bool wordPattern(string pattern, string str)
  {
    set<string> uniq;
    vector<char> patt(129, -1);
    vector<string> vs = Split(str, " ");
    if (vs.size() != pattern.size())
      return false;
    for (size_t i = 0; i != pattern.size(); i++)
    {
      if (patt[pattern[i]] == -1)
      {
        patt[pattern[i]] = i;
        if (uniq.find(vs[i]) != uniq.end()) return false;
        uniq.insert(vs[i]);
      }
      else if (vs[patt[pattern[i]]] != vs[i])
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution sol;
  string a = "abba";
  string b = "dog cat cat dog";
  cout << sol.wordPattern(a, b) << endl;
  return 0;
}
