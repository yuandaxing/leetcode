/*
 * author: daxing.yuan
 * create: 2018-05-06
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
    void Imp(TreeNode* root, vector<int>& result)
    {
        if(root == nullptr)
        {
            return ;
        }
        result.push_back(root->val);
        std::sort(result.begin(), result.end());
        auto beg = std::unique(result.begin(), result.end());
        result.erase(beg, result.end());
        if(result.size() > 2)
            result.pop_back();
        if(result.size() == 2 && root->val >= result.back())
            return ;
        if(root->left == nullptr)
            return ;
        Imp(root->left, result);
        Imp(root->right, result);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> result;
        Imp(root, result);
        if(result.size() < 2)
            return -1;
        return result[1];
    }
};

int main()
{

    return 0;
}
