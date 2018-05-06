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

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id_2_e;
        for(auto c : employees)
        {
            id_2_e[c->id] = c;
        }
        unordered_set<int> ids;
        vector<Employee*> v;
        auto it = id_2_e.find(id);
        if(it == id_2_e.end())
        {
            return 0;
        }
        v.push_back(it->second);
        ids.insert(it->first);
        int sum = it->second->importance;
        while(!v.empty())
        {
            auto back = v.back();
            v.pop_back();
            for(auto e : back->subordinates)
            {
                if(ids.find(e) != ids.end())
                    continue;
                auto it = id_2_e.find(e);
                if(it == id_2_e.end())
                {
                    return 0;
                }
                v.push_back(it->second);
                ids.insert(it->first);
                sum += it->second->importance;
            }
        }
        return sum;
    }
};


int main()
{

    return 0;
}
