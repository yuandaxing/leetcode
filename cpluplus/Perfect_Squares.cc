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

/*
 * M = sqrt(n)
 * M*M  (M-1)*(M-1)
  F(n) = min(F(n-M*M)(M) + 1, F(n)(M-1))
 */


class Solution
{
public:

  void numSquares(int left, int max_v, int count)
  {
    if(count >= min_)
    {
     return ;
    }

    if (left == 0)
    {
      min_ = std::min(count, min_);
      return ;
    }
    int v = static_cast<int>(sqrt(left));
    max_v = std::min(v, max_v);
    numSquares(left - max_v*max_v, max_v, count+1);
    if (max_v > 1)
      numSquares(left, max_v-1, count);
  }
  int numSquares(int n)
  {
    numSquares(n, INT_MAX, 0);
    return min_;
  }

  Solution():min_(INT_MAX)
  {
  }
private:
  int min_;
};

int main()
{
  Solution sol;
  cout << sol.numSquares(13) << endl;
  Solution sol1;
  cout << sol1.numSquares(12) << endl;
  return 0;
}
