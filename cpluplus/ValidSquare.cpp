/*
 * author: daxing.yuan
 * create: 2018-05-06
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

struct Points
{
    int x,  y;
    Points(const vector<int>& v):
        x(v[0]), y(v[1]){}
};
bool operator<(const Points& lhs, const Points& rhs)
{
    if(lhs.x != rhs.x)
        return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

class Solution
{
public:
    bool checkB(Points& p1, Points& p2, Points& p3)
    {
        int x1 = p2.x - p1.x, y1 = p2.y - p1.y;
        int x2 = p3.y - p1.x, y2 = p3.y - p1.y;
        if(x1 == 0 && y1 == 0)
            return false;
        if(x1*x1 + y1 * y1 != x2*x2 + y2 * y2)
        {
            return false;
        }
        if(x1 * x2 + y1 * y2 != 0)
        {
            return false;
        }
        return true;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<Points> result {Points(p1), Points(p2), Points(p3), Points(p4)};
        std::sort(result.begin(), result.end());
        if(!checkB(result[0], result[1], result[2]))
            return true;
        return checkB(result[3], result[1], result[2]);
    }
};

int main()
{

    return 0;
}
