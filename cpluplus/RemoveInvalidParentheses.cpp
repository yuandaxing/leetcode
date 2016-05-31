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
class Solution
{
public:
  void ValidDelete(string& v, int32_t start, int32_t num1, int32_t num2,
                   vector<char>& stack, string& cur, vector<string>& result)
  {
    if (start >= static_cast<int>(v.size()))
    {
      if (num1 == 0 && num2 == 0)
      {
        result.push_back(cur);
      }
      return ;
    }
    if (num1 > 0 && v[start] == '(')
    {
      ValidDelete(v, start+1, num1-1, num2, stack, cur, result);
    }
    if (num2 > 0 && v[start] == ')')
    {
      ValidDelete(v, start+1, num1, num2 - 1, stack, cur, result);
    }
    if (v[start] == ')' && stack.empty())
      return ;
    cur.push_back(v[start]);
    if (v[start] == ')')
      stack.pop_back();
    else if (v[start] == '(')
      stack.push_back('(');
    ValidDelete(v, start+1, num1, num2, stack, cur, result);
    cur.pop_back();
    if (v[start] == ')')
      stack.push_back('(');
    else if (v[start] == '(')
      stack.pop_back();
  }
  vector<string> removeInvalidParentheses(string s)
  {
    vector<char> stack;
    int num1 = 0, num2 = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
      if (*it == '(')
      {
        stack.push_back(*it);
      }
      if (*it == ')')
      {
        if (stack.empty())
        {
          num2++;
        }
        else
        {
          stack.pop_back();
        }
      }
    }
    num1 = static_cast<int>(stack.size());
    vector<string> result;
    vector<char> stack1;
    string tmp;
    ValidDelete(s, 0, num1, num2, stack1, tmp, result);
    set<string> uniq(result.begin(), result.end());
    vector<string> ret(uniq.begin(), uniq.end());
    return ret;
  }
};

int main()
{
  string s = "((";
  Solution sol;
  vector<string> result = sol.removeInvalidParentheses(s);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << endl;
  }

  return 0;
}
