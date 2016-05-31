/*
 * author: yuandx
 * create: 2016-05-24
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
/*
 * algorithm
 * stack to calculate remove N '(', M ')'
 * C(m, M)C(n, N)
 *
 */
struct DelMemo
{
  int start, end;
  int type; //0 is left, 1 is right
  int num;
};
class Solution
{
public:
  vector<DelMemo> to_delete_;
  void ValidDelete(string& v, int32_t start, bool type, int32_t num,
                   vector<char>& stack, string& cur, vector<string>& result)
  {
    if (start >= static_cast<int>(v.size()))
    {
      if (num == 0)
      {
        result.push_back(cur);
      }
      return ;
    }
    bool could_remove = (type == 0 && v[start] == '(') ||
      (type == 1 && v[start] == ')');
    if (num > 0 && could_remove)
    {
      ValidDelete(v, start+1, type, num-1, stack, cur, result);
    }
    if (v[start] == ')' && stack.empty())
      return ;
    cur.push_back(v[start]);
    if (v[start] == ')')
      stack.pop_back();
    else if (v[start] == '(')
      stack.push_back('(');
    ValidDelete(v, start+1, type, num, stack, cur, result);
    cur.pop_back();
    if (v[start] == ')')
      stack.push_back('(');
    else if (v[start] == '(')
      stack.pop_back();
  }
  vector<string> Splice(string s)
  {
    vector<string> ret = {""};
    for (auto it = to_delete_.begin(); it != to_delete_.end(); ++it)
    {
      vector<char> stack;
      vector<string> result, tmp;
      string cur, sub_string = s.substr(it->start, it->end-it->start+1);
      ValidDelete(sub_string, 0, it->type, it->num, stack, cur, result);
      set<string> uniq(result.begin(), result.end());
      for (auto it = uniq.begin(); it != uniq.end(); ++it)
      {
        for (auto it1 = ret.begin(); it1 != ret.end(); ++it1)
        {
          tmp.push_back(*it1 + *it);
        }
      }
      ret.swap(tmp);
    }
    return ret;
  }
  vector<string> removeInvalidParentheses(string s)
  {
    vector<char> stack;
    int prev = 0, cur = 0;
    for (auto it = s.begin(); it != s.end(); ++it, cur++)
    {
      if (*it == '(')
      {
        stack.push_back(*it);
      }
      if (*it == ')')
      {
        if (stack.empty())
        {
          to_delete_.push_back({prev, cur, 1, 1});
          prev = cur+1;
        }
        else
        {
          stack.pop_back();
        }
      }
    }
    to_delete_.push_back({prev, cur - 1, 0, static_cast<int>(stack.size())});
    return Splice(s);
  }
};

int main()
{
  string s = ")(";
  Solution sol;
  vector<string> result = sol.removeInvalidParentheses(s);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << endl;
  }

  return 0;
}
