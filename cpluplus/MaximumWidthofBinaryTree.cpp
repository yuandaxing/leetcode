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

class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        std::vector<pair<TreeNode*, int>> cur, next;
        cur.emplace_back(root, 0);
        int max_d = 1;
        while(!cur.empty())
        {
            if(cur.size() > 1)
            {
                auto front = cur.front(), back = cur.back();
                max_d = std::max(max_d, back.second - front.second + 1);
            }
            for(auto e : cur)
            {
                if(e.first->left)
                {
                    next.emplace_back(e.first->left, 2*e.second);
                }
                if(e.first->right)
                {
                    next.emplace_back(e.first->right, 2*e.second+1);
                }
            }
            cur.clear();
            cur.swap(next);
        }
        return max_d;
    }
};

int main()
{

    return 0;
}
