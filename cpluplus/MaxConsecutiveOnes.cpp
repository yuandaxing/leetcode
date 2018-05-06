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

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() <= 0)
        {
            return 0;
        }
        int prev = nums[0], max_l = nums[0] == 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == 1 && nums[i-1] == 0)
                prev = i;
            if(nums[i] == 0 && nums[i-1] == 1)
                max_l = std::max(max_l, i - prev);
        }
        return max_l;
    }
};

int main()
{

    return 0;
}
