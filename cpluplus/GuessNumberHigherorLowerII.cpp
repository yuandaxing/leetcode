/*
 * author: daxing.yuan
 * create: 2018-05-05
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
 * F[i, L] = std::min(std::max{F[i, j-i], F[j, i+L-j]}+A[j])
 * F[i, 0] = 0, F[i, 1] = 0
 */

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> F(n+2, vector<int>(n+1, 0));
        for(int L = 0; L <= n; L++)
        {
            for(int i = 1; i <= n - L+1; i++)
            {
                if(L < 2)
                {
                    F[i][L] = 0;
                    continue;
                }
                int val = INT_MAX;
                for(int j = i; j < i+L; j++)
                {
                    int cur = std::max(F[i][j-i], F[j+1][i+L-j-1])+ j;
                    val = std::min(val, cur);
                }
                F[i][L] = val;
            }
        }
        return F[1][n];
    }
};
int main()
{
    Solution s;
    cout << s.getMoneyAmount(1);
    return 0;
}
