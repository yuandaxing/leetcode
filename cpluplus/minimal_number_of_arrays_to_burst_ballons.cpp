/*
 * author: daxing.yuan
 * create: 2017-10-31
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
    int findMinArrowShots(vector<pair<int, int>>& points) {
        std::sort(points.begin(), points.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs)
                  {
                      if (lhs.first != rhs.first)
                      {
                          return lhs.first < rhs.first;
                      }
                      return lhs.second < rhs.second;
                  });
        long min = INT_MAX + 1l, count = 0;
        for (auto& i : points)
        {
            if (i.first > min)
            {
                count += 1;
                min = INT_MAX + 1l;
            }
            min = std::min<long>(i.second, min);
        }
        if (min != -1)
            count+=1;
        return count;
    }
};

int main()
{

    return 0;
}
