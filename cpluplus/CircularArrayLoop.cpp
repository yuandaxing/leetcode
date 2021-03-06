/*
 * author: daxing.yuan
 * create: 2018-03-30
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
    bool circularArrayLoop(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                continue;
            int cur = i, next = (nums[i] + i) % nums.size();
            int count = 1, sign = nums[cur] > 0 ? 1 : -1;
            nums[cur] = 0;
            while(nums[next] != 0 && nums[next] * sign > 0)
            {
                cur = next;
                next = (nums[cur] + cur) % nums.size();
                count++;
                nums[cur] = 0;
            }
            if(nums[next] == 0 && count > 2)
                return true;
        }
        return false;
    }
};
int main()
{

    return 0;
}
