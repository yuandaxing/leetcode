/*
 * author: daxing.yuan
 * create: 2018-05-04
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


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> keep;
        int count = 0;
        for(auto a : answers)
        {
            if(a == 0)
            {
                count += 1;
                continue;
            }
            keep[a] += 1;
            if(keep[a] % (a+1) ==  1)
                count += a + 1;
        }
        return count;
    }
};

int main()
{

    return 0;
}
