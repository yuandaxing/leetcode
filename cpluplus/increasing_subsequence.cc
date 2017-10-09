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
    Solution():uniq(Solution::LT)
    {

    }
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        uniq.clear();
        vector<vector<int>> ret;
        for(int i = 1; i <nums.size(); i++)
        {
            int size = ret.size();
            for (int k = 0; k < i; k++)
            {
                if (nums[i] < nums[k])
                    continue;
                vector<int> cur = {nums[k], nums[i]};
                if (uniq.count(cur) == 0)
                {
                    ret.push_back(cur);
                    uniq.insert(cur);
                }
            }
            for (int k = 0; k < size; k++)
            {
                vector<int> cur = ret[k];
                if (nums[i] < cur.back())
                    continue;
                cur.push_back(nums[i]);
                if (uniq.count(cur) == 0)
                {
                    ret.push_back(cur);
                    uniq.insert(cur);
                }
            }
        }
        return ret;
    }
    static bool LT(const vector<int>& v1, const vector<int>& v2)
    {
        int size = std::min(v1.size(), v2.size());
        for (int i = 0; i < size; i++)
        {
            if (v1[i] != v2[i])
                return v1[i] < v2[i];
        }
        return v1.size() < v2.size();
    }
private:
    set<vector<int>, std::function<bool(const vector<int>&, const vector<int>&)>> uniq;
};


int main()
{
    vector<int> input = {4, 6, 7, 7};
    Solution s;
    auto ret = s.findSubsequences(input);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for (auto it1 = (*it).begin(); it1 != (*it).end(); ++it1)
        {
            cout << *it1 << " ";
        }
        cout << endl;
    }
    return 0;
}
