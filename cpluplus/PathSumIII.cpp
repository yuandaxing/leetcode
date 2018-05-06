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

/*
 * 长度为2以上只有一个的需要分别处理
 */
class Solution
{
public:
    int pathFrom(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return 0;
        return (root->val == sum) + pathFrom(root->left, sum - root->val) + pathFrom(root->right, sum - root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        return pathFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

int main()
{

    return 0;
}
