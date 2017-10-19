/*
 * author: daxing.yuan
 * create: 2017-10-12
 * email: daxing.yuan@yitu-inc.com
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
#include <queue>

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
using std::deque;
/*
  1 C(10, 1)
  2 C(10, 1) + 90 - C(9, 1)
  3 C(10, 1) + 90 - C(9, 1) + 900 - C(9, 1){C(2, 1) + C(9, 1)}
  K C(10, 1) + 90 - C(9, 1) + 900 -                           9000 - C(9, 1){C(3, 1) + C(9, 1){C(2,1 + C)}}
  F(K)长度为K的uniq个数9*9*8*(9-k+1)
  F
 */
class Solution
{
public:
    vector<int> num;
    Solution()
    {
        num.push_back(10);
        int ret = 9;
        for (int i = 0; i < 9; i++)
        {
            ret *= (9-i);
            num.push_back(ret);
            num[i+1] += num[i];
        }
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (n >= 10)
            return num[9];
        return num[n-1];
    }
};

int main()
{

    return 0;
}
