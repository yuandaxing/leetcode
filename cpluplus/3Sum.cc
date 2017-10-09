/*
 * author: yuandx
 * create: 2015-10-03
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
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

struct Triple
{
    int x, y, z;
    Triple(int x1, int y1, int z1): x(x1), y(y1), z(z1)
    {
    }
};
bool operator<(const Triple& lhs, const Triple& rhs)
{
    if (lhs.x != rhs.x)
        return lhs.x - rhs.x > 0;
    if (lhs.y != rhs.y)
        return lhs.y - rhs.y > 0;
    if (lhs.z != rhs.z)
        return lhs.z - rhs.z > 0;
    return false;
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i]==nums[i-1])
                continue;
            for (int j = i+1, k = size -1; j < k; )
            {
                if (j > i+1 && nums[j] == nums[j-1])
                {
                    j++;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ret;
    }
};
int main()
{
    Solution sol = Solution();
    vector<int> input = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    for (auto & e : sol.threeSum(input))
    {
        cout << e[0] << " " << e[1] << " " << e[2] << "\t";
    }
    cout << endl;
    return 0;
}
