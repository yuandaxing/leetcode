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
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int cur = 0, line = 0;
        for(auto c : S)
        {
            if(cur + c <= 100)
            {
                cur += c;
            }
            else
            {
                cur = 0;
                line++;
            }
        }
        return vector<int>{cur > 0 ? line+1 : line , cur};
    }
};

int main()
{

    return 0;
}
