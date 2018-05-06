/*
 * author: daxing.yuan
 * create: 2018-01-03
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
  F[N] =  (1+N)*N/2
 */
class Solution
{
public:
    int findSubstringInWraproundString(string p) {
        if(p.size() == 0)
            return 0;
        vector<int> count(26, 0);
        int prev = 0;
        for(int i = 0; i < p.size(); i++)
        {
            if('a' + (p[i-1]-'a'+1)% 26 != p[i])
            {
                prev = i;
            }
            int& c = count[p[i] - 'a'];
            c = std::max(i-prev + 1, c);
        }
        return std::accumulate(count.begin(), count.end(), 0);
    }
};

int main()
{

    return 0;
}
