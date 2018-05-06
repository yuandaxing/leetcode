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
      int getMaxRepetitions1(string s1, int n1, string s2, int n2) {
        for(auto c : s2) {
            // preventive checkings, it could be O(n), but who cares.
            if (s1.find(c) == string::npos) return 0;
        }
        int p1 = 0, p2 = 0, mark = 0;
        while(p1 < s1.length() * n1) {
            char c = s2[p2 % s2.length()];
            while(s1[p1 % s1.length()] != c && p1 < s1.length() * n1) p1 ++;
            p2++;
            p1++;
            // optimization part below
            if (p2 % s2.length() == 0) {
                if (p2 == s2.length()) {
                    mark = p1; // mark the position in s1, when the first s2 ends
                } else if (p1 % s1.length() == mark % s1.length()) {
                    // s1 reaches the same position, which means the repeating cycle found.
                    //Then we can leap forward.
                    int round = (s1.length() * n1 - p1) / (p1 - mark);
                    p1 += round * (p1 - mark);
                    p2 += round * (p2 - s2.length());
                }
            }
        }
        return p2 / s2.length() / n2;
    }
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        for(auto c : s2) {
            // preventive checkings, it could be O(n), but who cares.
            if (s1.find(c) == string::npos) return 0;
        }
        int end1 = s1.size() * n1;
        int i = 0, j = 0;
        while(j < end1)
        {
            if(s2[i%s2.size()] == s1[j%s1.size()])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
            if(j % s1.size() == 0 && i % s2.size() == 0)
            {
                break;
            }
        }
        if(j == end1)
        {
            return i / s2.size( ) /n2;
        }
        int d1 = j / s1.size(), d2 = i / s2.size();
        return d2*n1/(d1*n2);
    }
};

int main()
{
    Solution s;
    cout << s.getMaxRepetitions("acb", 4, "ab", 2);
    return 0;
}
