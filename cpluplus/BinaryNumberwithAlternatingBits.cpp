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

class Solution
{
public:
    bool hasAlternatingBits(int n) {
        int prev = n&1;
        n >>= 1;
        while (n)
        {
            int cur = n & 1;
            if(cur == prev)
                return false;
            prev = cur;
            n >>= 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.hasAlternatingBits(10);
    return 0;
}
