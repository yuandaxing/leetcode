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
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0u)
        {
            return 0;
        }
        int prev = 0, max = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] <= nums[i-1])
            {
                prev = i;
            }
            max = std::max(max, i - prev + 1);
        }
        return max;
    }
};

int main()
{

    return 0;
}
