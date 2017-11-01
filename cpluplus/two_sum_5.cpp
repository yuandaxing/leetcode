/*
 * author: daxing.yuan
 * create: 2017-11-01
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
    vector<int> result;
    void insertV(TreeNode* v)
    {
        if (v == NULL)
            return ;
        insertV(v->left);
        result.push_back(v->val);
        insertV(v->right);
    }
    bool findTarget(TreeNode* root, int k) {
        insertV(root);
        int left = 0, right = result.size() - 1;
        while (left < right)
        {
            int val = result[left] + result[right];
            if (val < k)
            {
                left++;
            }
            else if (val > k )
            {
                right--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}
