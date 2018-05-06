/*
 * author: daxing.yuan
 * create: 2018-05-04
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
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
       vector<int> plate(26, 0), word(26, 0);
        string min_w;
        for(auto c : licensePlate)
        {
            char v = tolower(c);
            if(v>='a' && v <= 'z')
            {
                plate[v-'a']+=1;
            }
        }
        int min_l = INT_MAX;
        for(auto& str : words)
        {
            word = plate;
            for(auto c : str)
            {
                char v = tolower(c);
                if(v>='a' && v <= 'z')
                {
                    if(word[v-'a'] != 0)
                        word[v-'a'] -= 1;
                }
            }
            if(std::count(word.begin(), word.end(), 0) == 26 && str.size() < min_l)
            {
                min_l = str.size();
                min_w = str;
            }
        }
        return min_w;
    }
};

int main()
{
    string plate = "1s3 PSt";
    vector<string> words = {"step","steps","stripe","stepple"};
    Solution s;
    cout << s.shortestCompletingWord(plate, words);
    return 0;
}
