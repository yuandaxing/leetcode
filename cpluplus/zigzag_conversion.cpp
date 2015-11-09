/*
 * author: yuandx
 * create: 2015-11-06
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
  string convert(string s, int numRows)
  {
    if (numRows == 1)
    {
      return s;
    }
    int size = static_cast<int>(s.size());
    string result;
    for (int i = 0; i <= numRows-1; i++)
    {
      for (int j = i; j < size; j += 2*numRows - 2)
      {
        result.push_back(s[j]);
        if (i != 0 && i != numRows - 1 &&
            j + 2*numRows - 2 - 2 * i < size)
        {
          result.push_back(s[j + 2*numRows - 2 - 2 * i]);
        }
      }
    }
    return result;
  }
};

int main()
{

  return 0;
}
