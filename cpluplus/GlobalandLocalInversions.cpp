/*
 * author: daxing.yuan
 * create: 2018-04-29
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
/*
 *
 */
class Solution
{
public:
    bool isIdealPermutation(vector<int>& A) {
        int prev = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] < A[prev])
            {
                std::swap(A[i], A[prev]);
                prev = i+1;
            }
            else
            {
                prev = i;
            }
        }
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i-1] > A[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}
