/*
 * author: yuandx
 * create: 2015-11-17
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
  vector<string> letterCombinations(string digits)
  {
    const string num_2_str[] = {" ", "", "abc", "def", "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};
    for (size_t i = 0; i != digits.size(); i++)
    {
      vector<string> tmp;
      for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
      {
        const string& cur = num_2_str[digits[i]-'0'];
        for (size_t j = 0; j != cur.size(); j++)
        {
          string tmp_str(*it);
          tmp_str.push_back(cur[j]);
          tmp.push_back(tmp_str);
        }

      }
      tmp.swap(result);
    }
    if (result.size() == 1 && result[0] == "")
      result.clear();
    return result;
  }
};

int main()
{

  return 0;
}
