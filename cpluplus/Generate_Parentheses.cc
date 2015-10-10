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
class Solution {
public:
  void AuxiliaryGen(vector<string>& result, int n)
  {
    if (n == 0)
      return ;
    if (n == 1)
    {
      result.push_back("()");
      return ;
    }
    vector<string> tmp;
    AuxiliaryGen(tmp, n-1);
    std::for_each(tmp.begin(), tmp.end(), [&result](const string& e){
        result.push_back('(' + e +')');
      });
    for (int i = 1; i < n; i++)
    {
      vector<string> tmp1, tmp2;
      AuxiliaryGen(tmp1, i);
      AuxiliaryGen(tmp2, n-i);
      for (const string& e1 : tmp1)
      {
        for (const string& e2 : tmp2)
        {
          result.push_back(e1 + e2);
        }
      }
    }
  }
  vector<string> generateParenthesis(int n)
  {
    vector<string> tmp, result;
    set<string> s;
    AuxiliaryGen(tmp, n);
    for_each(tmp.begin(), tmp.end(), [&s](const string& e){
        s.insert(e);
      });
    for_each(s.begin(), s.end(), [&result](const string& e){
        result.push_back(e);
      });
    return result;
  }
};
int main()
{
  Solution sol = Solution();
  for (const string& e : sol.generateParenthesis(3))
  {
    cout << e << "\t";
  }
  cout << endl;
  return 0;
}
