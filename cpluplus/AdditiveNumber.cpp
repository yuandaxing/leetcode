/*
 * author: yuandx
 * create: 2016-05-15
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
  bool CheckAdditive(vector<int>& vec, int i, int j)
  {
    int size = static_cast<int>(vec.size());
    while (j != size)
    {

    }
  }
  bool isAdditiveNumber(string num)
  {
    vector<int> val;
    int size = static_cast<int>(num.size());
    int min_left = size / 3, max_before = size - min_left;
    for (auto it = num.begin(); it != num.end(); ++it)
    {
      val.push_back(*it - '0');
    }
    for (int i = 1; i < max_before; i++)
    {
      for (int j = 1; j < max_before - i; j++)
      {
        if (CheckAdditive(val, i, j+i))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{

  return 0;
}
