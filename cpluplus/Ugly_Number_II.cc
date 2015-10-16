/*
 * author: yuandx
 * create: 2015-10-10
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
/*
 *1 2 3 2*2 5 2*3 2*2*2 3*3 2*5 2*2*3 3*5 2*2*2*2 3*3*2 2*2*5
 *
 */
class Solution
{
public:
  int nthUglyNumber(int n)
  {
    vector<int> result(n, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    int v2 = 2, v3 = 3, v5 = 5;
    for(int i = 1; i < n; i++)
    {
      int cur = std::min(std::min(v2, v3), v5);
      result[i] = cur;
      if (cur == v2)
      {
        i2++;
        v2 = result[i2]* 2;
      }

      if (cur == v3)
      {
        i3++;
        v3 = result[i3]* 3;
      }

      if (cur == v5)
      {
        i5++;
        v5 = result[i5] * 5;
      }
    }
    cout << endl;
    return result[n-1];
  }
};

int main()
{
  Solution sol;
  sol.nthUglyNumber(10);
  return 0;
}
