/*
 * author: daxing.yuan
 * create: 2018-04-28
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

/* i is amount, j is for coins idx
  F[i][j]  = F[i][j-1] + F[i-coins[j]][j]
 */
class Solution
{
public:
    int change(int amount, vector<int>& coins) {
        if(coins.size() == 0)
        {
            return amount == 0;
        }
        vector<vector<int>> F(amount+1, vector<int>(coins.size(), 0));
        F[0] = vector<int>(coins.size(), 1);
        for(int j = 0; j < coins.size(); j++)
        {
            for(int i = 1; i <= amount; i++)
            {
                if(j-1>=0)
                    F[i][j] += F[i][j-1];
                if(i-coins[j]>=0)
                    F[i][j] += F[i-coins[j]][j];
            }
        }
        return F[amount][coins.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2, 5};
    cout << s.change(5, a);
    return 0;
}
