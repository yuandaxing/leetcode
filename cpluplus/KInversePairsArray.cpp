/*
 * author: daxing.yuan
 * create: 2018-05-06
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
 * F[N, K] = F[N-1, K]+F[N-1, K-1] + F[N-K-2]+F[N-1, 0],
 * F[N, 0] = 1, F[1 0] = 1, F[1...N] = 0
 */
class Solution
{
public:
    int kInversePairs(int n, int k) {
        const int mode  = 1e9+7;
        vector<vector<int>> F(n+1, vector<int>(k+1, 0));
        for(int i = 0; i <=k ; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == 0)
                {
                    F[j][i] = 1;
                    continue;
                }
                if(j == 1 && i > 0)
                {
                    F[j][i] = 0;
                    continue;
                }
                for(int z = 0; z <=i && z <= j-1; z++)
                {
                    F[j][i] += F[j-1][i-z];
                    F[j][i] %= mode;
                }

            }
        }
        return F[n][k];
    }
};

int main()
{
    Solution s;
    cout << s.kInversePairs(3, 1);
    return 0;
}
