/*
 * author: yuandx
 * create: 2015-11-19
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
  void GenHelper(vector<string>& result, int left, int right)
  {
    if (left == 0 && right == 0)
    {
      return ;
    }

    vector<string> tmp1, tmp2;
    if (left > 0)
    {
      tmp1.insert(tmp1.end(), result.begin(), result.end());
      for (auto it = tmp1.begin(); it != tmp1.end(); ++it)
      {
        it->push_back('(');
      }
      GenHelper(tmp1, left-1, right);
    }
    if (right > left)
    {
      tmp2.insert(tmp2.end(), result.begin(), result.end());
      for (auto it = tmp2.begin(); it != tmp2.end(); ++it)
      {
        it->push_back(')');
      }
      GenHelper(tmp2, left, right-1);
    }
    result.clear();
    result.swap(tmp1); result.insert(result.begin(), tmp2.begin(), tmp2.end());
  }
  vector<string> generateParenthesis(int n)
  {
    vector<string> result = {""};
    GenHelper(result, n, n);
    return result;
  }
};

int main()
{

  return 0;
}
