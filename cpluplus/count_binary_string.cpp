/*
 * author: daxing.yuan
 * create: 2017-10-24
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
    int countBinarySubstrings(string s) {
        int count[2] = {0, 0}, size = s.size();
        int total = 0, step =0;
        for (int i = 0; i < size; i+=step)
        {
            std::fill_n(count, 2, 0);
            step = 0;
            for (int j = i; j < size; j++)
            {
                if (j > i && s[j] != s[j-1])
                {
                    if (count[0] > 0 && count[1] > 0)
                    {
                        step = std::abs(count[0] - count[1]);
                        break;
                    }
                }

                count[s[j]-'0']+=1;
                if (j > i && count[0] == count[1])
                {
                    total += count[0];
                    step = count[0];
                    break;
                }
            }
            step = step == 0 ? std::abs(count[0] - count[1]) : step;
        }
        return total;
    }
};

int main()
{
    string v = "00110";
    Solution s;
    cout << s.countBinarySubstrings(v);
    return 0;
}
