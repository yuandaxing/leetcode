/*
 * author: daxing.yuan
 * create: 2018-03-29
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
    int TileInternal(TreeNode* root, int& sum)
    {
        if(root == NULL)
        {
            sum += 0;
            return 0;
        }
        int left = TileInternal(root->left, sum), right = TileInternal(root->right, sum);
        sum += abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        TileInternal(root, sum);
        return sum;
    }
};

int main()
{

    return 0;
}
