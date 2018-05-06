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

class Solution {
public:
    string decodeString(string s) {
        auto end = s.find_first_of(']', 0);
        while(end != string::npos)
        {
            auto beg = s.find_last_of('[', end);
            auto num_b = s.find_last_not_of("0123456789", beg-1);
            auto str = s.substr(beg+1, end - beg - 1);
            int num = stoi(s.substr(num_b+1, beg - (num_b+1)));
            string parse;
            for(int i = 0; i < num; i++)
            {
                parse += str;
            }
            s.erase(num_b+1, end+1 - (num_b+1));
            s.insert(num_b+1, parse);
            end = s.find_first_of(']', 0);
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
    return 0;
}
