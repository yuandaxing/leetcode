/*
 * author: daxing.yuan
 * create: 2017-10-26
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
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (auto& t : timePoints)
        {
            int d1 = stoi(t.substr(0, 2)), d2 = stoi(t.substr(3, 2));
            v.push_back(d1 * 60 + d2);
        }
        std::sort(v.begin(), v.end());
        int min = INT_MAX;
        for (int i = 0; i < v.size(); i++)
        {
            int d = v[i] - v[(i-1+v.size())%v.size()];
            min = std::min((d+24*60)%(24*60), min);
        }
        return min;
    }
};

int main()
{
    vector<string> d= {"23:59","00:00"};
    Solution s;
    cout << s.findMinDifference(d);
    return 0;
}
