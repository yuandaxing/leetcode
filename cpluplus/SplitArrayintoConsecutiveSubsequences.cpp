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
    bool isPossible(vector<int>& nums) {
        if(nums.size() < 3)
        {
            return false;
        }
        deque<int> track;
        
        for(auto cur  = std::lower_bound(nums.begin(), nums.end(), nums[0]),
                next = std::upper_bound(cur, nums.end(), *cur);
            cur != nums.end();
            cur = next, next = std::upper_bound(cur, nums.end(), *cur))
        {
            int size = next - cur;
            while(track.size() > size)
            {
                int front = track.front();
                if(*cur - front  < 3)
                    return false;
                track.pop_front();
            }
            while(size > track.size())
            {
                track.push_back(*cur);
            }
            if(*next != *cur + 1)
            {
                while(!track.empty())
                {
                    int front = track.front();
                    if(*cur - front + 1  < 3)
                        return false;
                    track.pop_front();
                }
            }
        }
        return true;
    }
};

int main()
{
    //vector<int> a = {1,2,3,3,4,5};
    vector<int> a = {1,2,3,3,4,4,5,5};
    //vector<int> a = {1,2,3,4,4,5};
    Solution s;
    cout << s.isPossible(a);
    return 0;
}
