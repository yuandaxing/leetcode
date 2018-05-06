/*
 * author: daxing.yuan
 * create: 2018-03-29
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
    bool canCross(vector<int>& stones) {
        vector<int> dis = {0, 1, -1};
        vector<vector<int>> steps(stones.size(), vector<int>());
        if(stones.size() == 0)
            return true;
        steps[0].push_back(0);
        for(int i = 0; i != stones.size(); i++)
        {
            sort(steps[i].begin(), steps[i].end());
            auto last = unique(steps[i].begin(), steps[i].end());
            steps[i].erase(last, steps[i].end());
            cout << endl << "i:" << i << endl;
            for(auto s : steps[i])
            {
                cout << s << " ";
                for(auto d : dis)
                {
                    if(s+d<=0) continue;
                    int value = stones[i] + s+d;
                    auto q = lower_bound(stones.begin() + i, stones.end(), value);
                    if(q == stones.end() ||  *q != value)
                    {
                        continue;
                    }
                    steps[q-stones.begin()].push_back(s+d);
                    if(q-stones.begin() == stones.size() - 1)
                    {
                        cout << "match:" << *q << " " << "value" << value << "stones[i]" << stones[i] << "s" << s
                             << "d" << d << endl;
                        return true;
                    }
                }
            }
            steps[i].clear();
        }
        return false;
    }
};

int main()
{
    vector<int> a= {0,1,2,3,4,8,9,11};
    Solution s;
    cout << s.canCross(a);
    return 0;
}
