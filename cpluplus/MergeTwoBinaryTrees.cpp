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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
        {
            return nullptr;
        }
        TreeNode * left = nullptr, *right = nullptr;
        left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        TreeNode * cur = new TreeNode(val);
        cur->left = left;
        cur->right = right;
        return cur;
    }
};

int main()
{

    return 0;
}
