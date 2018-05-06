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
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int val = nums[i], j = i;
            while(val -1 != j && nums[val-1] != val)
            {
                j = nums[val-1];
                val = nums[j];
                nums[val - 1] = val;
            }
            if(val - 1 == j && nums[val - 1] == val)
        }
    }
};

int main()
{

    return 0;
}
