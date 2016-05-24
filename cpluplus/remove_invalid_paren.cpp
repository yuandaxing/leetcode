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
  void DFS(string& str, int start, int delete_left, int delete_right);
  vector<string> removeInvalidParentheses(string s)
  {
    vector<char> stack;
    int delete_left = 0, delete_right = 0;
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
          delete_right++;
        }
        else
        {
          stack.pop_back();
        }
      }
    }
    delete_left = static_cast<int>(stack.size());


  }
};

int main()
{

  return 0;
}
