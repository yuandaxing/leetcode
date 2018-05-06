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
    int getI(char c)
    {
        return tolower(c) - 'a';
    }
    vector<string> findWords(vector<string>& words) {
        int c_2_value[26] = {
            1, 2, 2, 1, 0, 1, //f
            1, 1, 0, 1, 1, 1, //l
            2, 2, 0, 0, 0, 0, //r
            1, 0, 0, 2, 0, 2, //x
            0, 2,
        };
        vector<string> result;
        for(auto& w : words)
        {
            if(w.empty())
            {
                result.push_back(w);
            }
            bool c = true;
            int v = c_2_value[getI(w[0])];
            for(auto ch : w)
            {
                if(c_2_value[getI(ch)] != v)
                {
                    c = false;
                    break;
                }
            }
            if(c)
                result.push_back(w);
        }
    }
};

int main()
{

    return 0;
}
