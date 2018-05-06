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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> cur, next;
        vector<double> result;
        cur.push_back(root);
        while(!cur.empty())
        {
            double sum = 0;
            for(auto t : cur)
            {
                sum += t->val;
                if(t->left)
                {
                    next.push_back(t->left);
                }
                if(t->right)
                {
                    next.push_back(t->right);
                }
            }
            result.push_back(sum  / cur.size());
            cur.clear();
            cur.swap(next);
        }
        return result;
    }
};

int main()
{

    return 0;
}
