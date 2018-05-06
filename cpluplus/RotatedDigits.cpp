/*
 * author: daxing.yuan
 * create: 2018-04-29
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
  0, 1, 8 ,, 2, 5, 6, 9
  F[1] = 4
  F[2] = 7*7 +F[1] - 7 - 2*2
  F[3] = 7^3 + F[2] - 7^2 - 2*2
  F[n] = 7^n + F[n-1] - 7^n-1 - 2*3^n-1
 */
class Solution
{
public:
    Solution(): isRotate{true, true, true, false, false, true, true, false, true, true},
                same{true, true, false, false, false, false, false, false, true, false}
    {}
    bool CheckRotate(int val)
    {
        bool rval = true, rsame = true;
        while(val)
        {
            int cur = val % 10;
            rval &= isRotate[cur]; rsame &= same[cur];
            val /= 10;
        }
        return rval && !rsame ;
    }
    int rotatedDigits(int N)
    {
        int count = 0;
        for(int i = 1; i <= N; i++)
        {
            count += CheckRotate(i);
        }
        return count;
    }
private:
    const bool isRotate[10];
    const bool same[10];
};

int main()
{
    Solution s;
    cout << s.rotatedDigits(10);
    return 0;
}
