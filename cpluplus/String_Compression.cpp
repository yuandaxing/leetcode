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
    int compress(vector<char>& chars) {
        int size = static_cast<int>(chars.size()), insert_pos = 0, count = 0;
        if (size > 1)
        {
            insert_pos = 1;
            count = 1;
        }
        for (int i = 1; i <= size; i++)
        {
            if (chars[i] != chars[i-1] || i == size)
            {
                string result =  count == 1 ? "" : std::to_string(count);
                std::copy(result.begin(), result.end(), chars.begin() + insert_pos);
                insert_pos += result.size();
            }
            if (i < size)
            {
                chars[insert_pos++] = chars[i];
                count = 1;
            }
        }
        chars.resize(insert_pos);
        return insert_pos;
    }
};

int main()
{

    return 0;
}
