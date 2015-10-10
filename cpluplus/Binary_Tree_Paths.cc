/*
 * author: yuandx
 * create: 2015-10-10
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
  void Auxiliary(TreeNode* root, vector<string> path, vector<string>& result)
  {
    if (root == NULL)
      return ;
    ostringstream os;
    os << root->val;
    path.push_back(os.str());
    if (root->left == NULL && root->right == NULL)
    {
      string cur = path[0];
      for (size_t i = 1; i != path.size(); ++i)
      {
        cur += "->" + path[i];
      }
      result.push_back(cur);
      path.pop_back();
      return ;
    }
    if (root->left)
    {
      Auxiliary(root->left, path, result);
    }
    if (root->right)
    {
      Auxiliary(root->right, path, result);
    }
    path.pop_back();
  }

  vector<string> binaryTreePaths(TreeNode* root)
  {
    vector<string> result, path;
    Auxiliary(root, path, result);
    return result;
  }
};
int main()
{

  return 0;
}
