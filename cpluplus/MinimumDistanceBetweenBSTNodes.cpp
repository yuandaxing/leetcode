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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution
{
public:
    void mindiffImp(TreeNode* root, int& mindiff, int& max, int& min)
    {
        mindiff = INT_MAX;
        if(root == nullptr)
        {
            mindiff = 0;
            max = min = 0;
            return ;
        }
        max = min = root->val;
        if(root->left)
        {
            int x = INT_MAX, y = 0, z = 0;
            mindiffImp(root->left, x, y, z);
            mindiff = std::min(std::min(mindiff, root->val - y), x) ;
            min = z;
        }
        if(root->right)
        {
            int x = INT_MAX, y = 0, z = 0;
            mindiffImp(root->right, x, y, z);
            mindiff = std::min(std::min(mindiff, x), z - root->val);
            max = y;
        }
    }
    int minDiffInBST(TreeNode* root) {
        int mindiff = 0, max = 0, min = 0;
        mindiffImp(root, mindiff, max, min);
        return mindiff;
    }
};

int main()
{

    return 0;
}
