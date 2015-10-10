#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using std::stack;
using std::fill_n;
using std::cout;
using std::vector;
using std::string;

void ReplaceAll(string& str, const string& from, const string& to)
{
  if (from.empty())
  {
    return ;
  }
  size_t pos = 0;
  for (pos = str.find(from, pos); pos != string::npos; pos = str.find(from, pos))
  {
    str.replace(pos, from.size(), to);
    pos += to.size();
  }
}
class Solution {
public:
  int calculate(string s)
  {
      ReplaceAll(s, " ", "");
      stack<int> context, ope;
      int num = 0, result = 0, sign = 1;
      for (int i = 0; i != s.size(); i++)
      {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
          num = num * 10 + c - '0';
        }
        else
        {
          result += num * sign;
          switch (c)
          {
          case '(':
            context.push(result);
            ope.push(sign);
            num = result = 0;
            sign = 1;
            break;
          case ')' :
            result = context.top() + ope.top() * result;
            context.pop();
            ope.pop();
            break;
          case '+' :
            sign = 1;
            break;
          case '-' :
            sign = -1;
            break;
          }
        }
      }
      return result += num * sign;
    }
};
