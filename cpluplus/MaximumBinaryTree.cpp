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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* Imp(vector<int>& nums, int start, int end)
    {
        if(start >= end)
        {
            return nullptr;
        }
        auto it = std::max_element(nums.begin() + start, nums.begin() + end);
        TreeNode * n = new TreeNode(*it);
        n->left = Imp(nums, start, it - nums.begin());
        n->right = Imp(nums, it - nums.begin() + 1, end);
        return n;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Imp(nums, 0, nums.size());
    }
};

int main()
{
    vector<int> v = {3,2,1,6,0,5};
    Solution s;
    cout << s.constructMaximumBinaryTree(v);
    return 0;
}
