/*
 * author: daxing.yuan
 * create: 2018-03-30
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(asteroids[i] > 0)
            {
                result.push_back(asteroids[i]);
                continue;
            }
            bool keep = true;
            while(!result.empty())
            {
                if(result.back() < 0)
                {
                    break;
                }
                if(result.back() < abs(asteroids[i]))
                    result.erase(--result.end());
                else if(result.back() == abs(asteroids[i]))
                {
                    result.erase(--result.end());
                    keep = false;
                    break;
                }
                else
                {
                    keep = false;
                    break;
                }
            }
            if(keep)
                result.push_back(asteroids[i]);
        }
        return result;
    }
};

int main()
{

    return 0;
}
