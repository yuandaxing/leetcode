/*
 * author: daxing.yuan
 * create: 2017-10-31
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
    int interal(long n)
    {
        if (n == 1)
            return 0;
        if (n % 2 == 0)
            return 1+interal(n/2);
        return std::min(interal(n-1), interal(n+1));
    }
    int integerReplacement(int n) {
        return interal(n);
    }
};

int main()
{

    return 0;
}
