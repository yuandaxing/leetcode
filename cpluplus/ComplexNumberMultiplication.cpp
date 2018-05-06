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
    void getab(const string& s, int& a, int& b)
    {
        auto sep = s.find_first_of("+", 1);
        a = std::stoi(s.substr(0, sep)), b = std::stoi(s.substr(sep+1));
    }
    string complexNumberMultiply(string a, string b) {
        int x1 = 0, y1 = 0;
        getab(a, x1, y1);
        int x2 = 0, y2 = 0;
        getab(b, x2, y2);
        int x3 = x1*x2 - y1 * y2;
        int y3 = x2*y1 + x1 * y2;
        return std::to_string(x3) + "+" + std::to_string(y3) + "i";
    }
};

int main()
{
    Solution s;
    cout << s.complexNumberMultiply("1+-1i", "1+-1i");
    return 0;
}
