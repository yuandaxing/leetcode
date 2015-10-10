/*
 * author: yuandx
 * create: 2015-09-30
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
/*
 * C(n) = 2 * n - 2;
 * CU(n) = n - 1
 * CD(n) = n - 1
 */
/* 0, 2*n-2
 * 1, 2*n-3
 * 2 2*n-4
 * 3 2*n-4
 * n-1, n-1 + 2*n-2 - n-1
 */
class Solution
{
public:
  string convert(string s, int numRows)
  {
    string ret;
    if (numRows == 1)
    {
      return s;
    }
    int size = static_cast<int>(s.size());
    for (int i = 0; i != numRows; ++i)
    {
      for (int j = 0; j < size; j += 2 *numRows - 2)
      {
        if (i + j < size)
        ret.push_back(s[i + j]);
        if (i != 0 && i != numRows - 1 && (2*numRows-2-i + j < size))
          ret.push_back(s[2*numRows-2-i + j]);
      }
    }
    return ret;
  }
};
int main()
{

  return 0;
}
