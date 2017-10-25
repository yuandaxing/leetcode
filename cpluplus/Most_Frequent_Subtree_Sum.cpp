/*
 * author: daxing.yuan
 * create: 2017-10-25
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
    unordered_map<int, int> q;
    int findFreq(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = findFreq(root->left), right = findFreq(root->right), v = root->val;
        q[left + right + v] += 1;
        return left + right + v;
    }
     vector<int> findFrequentTreeSum(TreeNode* root) {
                 vector<int> ret;
        findFreq(root);
        auto it = std::max_element(q.begin(), q.end(), [](unordered_map<int, int>::value_type & t1,
                                                          unordered_map<int, int>::value_type & t2)
                                   { return t1.second < t2.second; });
        if (it == q.end())
        {
            return ret;
        }
        for(auto& v : q)
        {
            if (it->second == v.second)
            {
                ret.push_back(v.first);
            }
        }
        return ret;
    }
};


int main()
{

    return 0;
}
