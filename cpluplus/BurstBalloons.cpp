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
/*
 *
 *    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 *    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 *    greedy algorithm
 *    find the minnumber in nums[1...size-2]
 *   F[i][len] = F[i][k-i] + F[k+1][len+i-k] + num[i]*num[k]*num[len-1]
 */
class Solution
{
public:
  int maxCoins(vector<int>& nums)
  {
    int size = static_cast<int>(nums.size());
    vector<vector<int>> F(size+1, vector<int>(size+1, 0));
    for (int len = 1; len <= size; len++)
    {
      for (int i = 0; i <= size - len; i++)
      {
        int max_v = INT_MIN;
        for (int k = i; k < i+len; k++)
        {
          int left = (i > 0 ? nums[i-1] : 1) ;
          int right = (i+len == size ? 1 : nums[i+len]);
          max_v = std::max(max_v, F[i][k-i] + F[k+1][len+i-k-1] + left * nums[k] * right);
        }
        F[i][len] = max_v;
      }
    }
    return F[0][size];
  }
};

int main()
{
  vector<int> v = {3, 1, 5, 8};
  Solution s;
  cout << s.maxCoins(v) << endl;
  return 0;
}
