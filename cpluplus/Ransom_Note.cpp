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
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(auto c : magazine)
        {
            count[c-'a'] +=1;
        }
        for (auto c: ransomNote)
        {
            count[c-'a'] -= 1;
            if (count[c-'a'] < 0)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}
