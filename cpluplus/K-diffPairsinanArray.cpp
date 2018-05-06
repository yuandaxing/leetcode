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
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        unordered_map<int, int> num_2_count;
        for(auto n : nums)
        {
            num_2_count[n] += 1;
        }
        int count = 0;
        for(auto e : num_2_count)
        {
            int v = e.first + k;
            if(num_2_count.find(v) == num_2_count.end())
                continue;
            count += (v == e.first) ? (e.second>=2) : 1;
        }
        return count;
    }
};

int main()
{

    return 0;
}
