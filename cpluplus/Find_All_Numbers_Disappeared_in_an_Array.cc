/*
 * author: daxing.yuan
 * create: 2017-10-08
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> ret;
        for (int i = 1, pos = 0; i <= nums.size() ;)
        {
            if(pos < nums.size() && nums[pos] <= i)
            {
                pos++;
            }
            else
            {
                if (pos == 0 || nums[pos-1] != i)
                {
                    ret.push_back(i);
                }
                i++;
            }
        }
        return ret;
    }
};


class Solution1
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret ;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[nums[i]-1] += nums.size();
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < nums.size())
                ret.push_back(i+1);
        }
        return ret;
    }
};

int main()
{
    vector<int> vec = {4,3,2,7,7,2,3,1};
    Solution s = Solution();
    auto ret = s.findDisappearedNumbers(vec);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    Solution1 s2 = Solution1();
    ret = s2.findDisappearedNumbers(vec);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
