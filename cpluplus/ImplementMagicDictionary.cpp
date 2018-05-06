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

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto& d : dict)
        {
            for(std::size_t i = 0; i != d.size(); i++)
            {
                string cur;
                cur.reserve(d.size() - 1);
                cur.insert(cur.end(), d.begin(), d.begin() + i);
                cur.insert(cur.end(), d.begin() + i + 1, d.end());
                mDict[cur].insert(d);
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(std::size_t i = 0; i != word.size(); i++)
        {
            string cur;
            cur.reserve(word.size() - 1);
            cur.insert(cur.end(), word.begin(), word.begin() + i);
            cur.insert(cur.end(), word.begin() + i + 1, word.end());
            if(mDict.find(cur) != mDict.end())
            {
                for(auto& s : mDict[cur])
                {
                    int count = 0;
                    for(int k = 0; k != word.size(); k++)
                    {
                        if(word[k] != s[k])
                            count++;
                        if(count >= 2)
                            break;
                    }
                    if(count == 1)
                        return true;
                }
            }
        }
        return false;
    }
private:
    unordered_map<string, set<string>> mDict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
int main()
{
    MagicDictionary  md;
    md.buildDict({"hello", "leetcode"});
    cout << md.search("hello");
    return 0;
}
