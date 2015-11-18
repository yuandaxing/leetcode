/*
 * author: yuandx
 * create: 2015-11-18
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
#include <stack>
using std::stack;
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
  bool isValid(string s)
  {
    stack<char> stack;
    for (size_t i = 0; i != s.size(); i++)
    {
      char c = s[i];
      if (c != ']' && c != ')' && c != '}')
      {
        stack.push(c);
      }
      else
      {
        if (stack.empty()) return false;
        char p = stack.top();
        stack.pop();
        if ((p == '[' && c == ']') ||
            (p == '(' && c == ')') ||
            (p == '{' && c == '}'))
        {
          continue;
        }
        return false;
      }
    }
    return stack.empty();
  }
};

int main()
{

  return 0;
}
