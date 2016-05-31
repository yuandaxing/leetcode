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
  bool isValidNum(vector<int>& v)
  {
    return v[0] != 0;
  }
  vector<int> Add(vector<int>& v1, vector<int>& v2)
  {
    std::reverse(v1.begin(), v1.end());
    std::reverse(v1.begin(), v1.end());
    vector<int> result;
    int c = 0;
    size_t size = std::max(v1.size(), v2.size());
    for (size_t i = 0; i < size || c != 0; i++)
    {
      int a1 = i < v1.size() ? v1[i] : 0;
      int a2 = i < v2.size() ? v2[i] : 0;
      int cur = a1+a2+c;
      c = cur / 10;
      cur = cur % 10;
      result.push_back(cur);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
  bool compare(vector<int>& result, vector<int>& vec, int beg)
  {
    int size2 = vec.size(), size1 = result.size();
    if (size2 - beg < size1)
      return false;
    std::equal(result.begin(), result.end(), vec.begin() + beg);
  }
  bool CheckAdditive(vector<int>& vec, int i, int j)
  {
    int size = static_cast<int>(vec.size());
    int prev = 0;
    while (j != size)
    {
      vector<int> n1(vec.begin() + prev, vec.begin() + i),
        n2(vec.begin()+i, vec.begin() + j);
      if (!isValidNum(n1) || !isValidNum(n2))
        return false;
      vector<int> n3 = Add(n1, n2);
      if (!compare(n3, vec, j))
        return false;
      prev = i;
      i = j;
      j = j + n3.size();
    }
    return true;
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
