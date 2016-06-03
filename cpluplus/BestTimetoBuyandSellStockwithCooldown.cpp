/*
 * author: yuandx
 * create: 2016-05-13
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
/*
 * S, B, C
 * S[i] = max{B[0...i-1] + A[i]}
 * B[i] = C[i-1] - A[i]
 * C[i] = max{S[i-1], C[i-1]}
 * max(S[size], C[size])
 */
class Solution
{
public:
  int maxProfit(vector<int>& prices)
  {
    if (prices.size() == 0)
      return 0;
    vector<int> S(prices.size(), 0), B(prices.size(), 0), C(prices.size(), 0);
    int size = static_cast<int>(prices.size());
    S[0] = 0;
    B[0] = -prices[0];
    C[0] = 0;

    for (int i = 1;  i< size; i++)
    {
      int max_b = INT_MIN;
      for (int j = 0; j < i; j++)
      {
        max_b = std::max(max_b, B[j]);
      }

      S[i] =max_b + prices[i];
      B[i] = C[i-1] - prices[i];
      C[i] = std::max(S[i-1], C[i-1]);
    }
    return std::max(C[size-1], S[size-1]);
  }
};

int main()
{
  vector<int> v = {1, 2, 3, 0, 2};
  vector<int> v2 = {1,2};
  Solution s;
  cout << s.maxProfit(v2) << endl;
  return 0;
}
