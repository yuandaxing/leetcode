/*
 * author: yuandx
 * create: 2016-06-04
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
  int bulbSwitch(int n)
  {
    vector<int> count(n+1, 0);
    for (int i = 2; i <= n; i++)
    {
      for (int k = i; k <= n; k+= i)
      {
        count[k] += 1;
      }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
      if ((count[i] & 1) == 0)
      {
        ret++;
      }
    }
    return ret;
  }
};

int main()
{
  Solution sol;
  cout << sol.bulbSwitch(3) << endl;
  return 0;
}
