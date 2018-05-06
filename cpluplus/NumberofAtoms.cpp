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
    map<string, int> key_2_c;
    string countOfAtoms(string formula) {
        auto end = formula.find_first_of(')', 0);
        while(end != string::npos)
        {
            auto beg = formula.find_last_of('(', end);
            auto num_e = formula.find_first_not_of("0123456789", end+1);
            auto str = formula.substr(beg+1, end - beg - 1);
            cout << formula << ", " << str << endl;
            num_e = num_e == string::npos ? formula.size() : num_e;
            int num = stoi(formula.substr(end+1, num_e - (end+1)));
            string parse;
            for(int i = 0; i < num; i++)
            {
                parse += str;
            }
            formula.erase(beg, num_e - beg);
            formula.insert(beg, parse);
            end = formula.find_first_of(')', 0);
        }
        for(auto it = formula.find_first_of("ABCDEFGHIGKLMNOPQRSTUVWXYZ", 0),
                next =  formula.find_first_of("ABCDEFGHIGKLMNOPQRSTUVWXYZ", it+1);
            it != string::npos;
            it = next, next = formula.find_first_of("ABCDEFGHIGKLMNOPQRSTUVWXYZ", it+1))
        {
            string substr = formula.substr(it, next - it);
            auto pos = substr.find_first_of("0123456789", 0);
            int count = pos == string::npos ? 1 : std::stoi(substr.substr(pos));
            key_2_c[substr.substr(0, pos)] += count;
        }
        string value;
        for(auto e : key_2_c)
        {
            value += e.first;
            value += e.second == 1 ? "" : std::to_string(e.second);
        }
        return value;
    }
};

int main()
{
    //string str = "H2O";
    //string str = "Mg(OH)2";
    string str = "K4(ON(SO3)2)2";
    Solution s;
    cout << s.countOfAtoms(str) << endl;
    return 0;
}
