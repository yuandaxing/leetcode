/*
 * author: daxing.yuan
 * create: 2018-04-28
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
    double area(const vector<int>& a1, const vector<int>& a2, const vector<int>& a3)
    {
        int x1 = a1[0] - a2[0], y1 = a1[1] - a2[1];
        int x2 = a1[0] - a3[0], y2 = a1[1] - a3[1];
        return abs(x1 * y2 - x2 * y1);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int size = static_cast<int>(points.size());
        double max = INT_MIN;
        for(int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                for(int k = j + 1; k < size; k++)
                {
                    max = std::max(max, area(points[i], points[j], points[k]));
                }
            }
        }
        return max/2;
    }
};

int main()
{

    return 0;
}
