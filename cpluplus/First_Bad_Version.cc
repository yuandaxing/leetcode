/*
 * author: yuandx
 * create: 2015-10-11
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
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
  int firstBadVersion(int n)
  {
    int left = 1, right = n;
    while (left <= right)
    {
      int mid = left + (right - left)/ 2;
      if (isBadVersion(mid))
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main()
{

  return 0;
}
