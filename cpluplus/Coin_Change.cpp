/*
 * author: yuandx
 * create: 2016-04-24
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
  /*
    F[i] = std::min(F[i-v] + 1), v is in coins
   */
  int coinChange(vector<int>& coins, int amount)
  {
    vector<int> F(amount+1, INT_MAX);
    F[0] = 0;
    for (int  i = 1; i <  static_cast<int>(F.size()); i++)
    {
      for (auto it = coins.begin(); it != coins.end(); ++it)
      {
        if (i - *it >= 0 && F[i - *it] < INT_MAX)
        {
          F[i] = std::min(F[i], F[i - *it] + 1);
        }
      }
    }
    return F[amount] == INT_MAX ? -1 : F[amount];
  }
};

int main()
{
  Solution s;
  vector<int> v = {1, 2, 5};
  cout << s.coinChange(v, 11) << endl;
  return 0;
}
