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
 * F[i, k] =
 *
 * 1.  A[i, j] and A[j+1, k-j-1]
 */
class Solution
{
public:
    bool xorGame(vector<int>& nums) {
        int xo = 0;
        for (int i: nums) xo ^= i;
        return xo == 0 || nums.size() % 2 == 0;
    }
};

int main()
{

    return 0;
}
