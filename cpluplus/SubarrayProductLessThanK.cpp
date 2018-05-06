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

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1, start = 0, end = 0, count = 0;
        for(; end != nums.size(); end++)
        {
            product *= nums[end];
            while(product >=k && start <= end)
            {
                product/=nums[start];
                start++;
            }
            count += (end - start+1);
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {1, 2, 3};
    cout << s.numSubarrayProductLessThanK(vec, 0);
    return 0;
}
