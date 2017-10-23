/*
 * author: daxing.yuan
 * create: 2017-10-22
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
private:
    vector<string> stringset;
    int target;
public:
    Solution():target(0)
    {
    }
    void DFS(string& num, int start, const string& cur, long prev, long prev_result, char prevops)
    {
        int size = static_cast<int>(num.size());
        if (start >= size && prev_result == target)
        {
            stringset.push_back(cur);
        }
        for (int i = start; i < size; i++)
        {
            string sub = num.substr(start, i - start +1);
            int v = 0;
            try{
                v = stoi(sub);
            }catch(std::exception& e)
            {
                continue;
            }
            if (sub[0] == '0' && i > start)
            {
                continue;
            }
            if (start == 0)
            {
                DFS(num, i+1, sub, v, v, '*');
                continue;
            }
            DFS(num, i+1, cur+"+"+sub, v, prev_result+v, '+');
            DFS(num, i+1, cur+"-"+sub, v, prev_result-v, '-');
            int cur_result = 0;
            if (prevops == '-')
                cur_result = prev_result + prev  - v * prev;
            if (prevops == '+')
                cur_result = prev_result  - prev  + v * prev;
            if (prevops == '*')
                cur_result = prev_result*v;
            DFS(num, i+1, cur+"*"+sub, v*prev, cur_result, prevops);
        }
    }
    vector<string> addOperators(string num, int target) {
        this->target = target;
        DFS(num, 0, "", 0, 0, '*');
        return stringset;
    }
};

int main()
{
    Solution s;
    const string num = "2147483647";
    int target = 2147483647;
    for (auto str: s.addOperators(num, target))
    {
        cout << str << endl;
    }
    return 0;
}
