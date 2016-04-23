/*
 * author: yuandx
 * create: 2016-04-24
 * email: yuandx@mvad.com
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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
  /*
    void MaxMoney(TreeNode* root, int with_root, int without_root)
    int l1, l2;
    MaxMoney(root->left, l1, l2);
    int r1, r2;
    MaxMoney(root->right, r1, r2);
    with_root = l2 + r2 + root->val
    without_root = l1 + r1;
   */
public:
  void MaxMoney(TreeNode* root, int& with_root, int& without_root)
  {
    if (root == NULL)
    {
      with_root = without_root = 0;
      return ;
    }
    int l1, l2, r1, r2;
    MaxMoney(root->left, l1, l2);
    MaxMoney(root->right, r1, r2);
    without_root = l1 + r1;
    with_root = std::max(l2 + r2 + root->val, without_root);
  }
  int rob(TreeNode* root) {
    int w1, w2;
    MaxMoney(root, w1, w2);
    return w1;
  }
};


int main()
{

  return 0;
}
