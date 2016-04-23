/*
 * author: yuandx
 * create: 2016-04-22
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
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
static inline std::vector<std::string> Split(const std::string& s, const std::string& delim)
{
  std::vector<std::string> ret;
  size_t last = 0, index = s.find_first_of(delim, last);

  while (index != std::string::npos)
  {
    ret.push_back(s.substr(last, index - last));
    last = index + 1;
    index = s.find_first_of(delim, last);
  }

  if (index - last > 0)
  {
    ret.push_back(s.substr(last, index - last));
  }
  return ret;
}

class Codec {
public:

    string serialize(TreeNode* root) {
      ostringstream os;
      vector<TreeNode*> queue;
      if (root == NULL)
      {
        os << 'N';
        return os.str();
      }
      os << root->val;
      queue.push_back(root->left);
      queue.push_back(root->right);
      for (size_t i = 0; i < queue.size(); ++i)
      {
        os << ',';
        if (queue[i] == NULL)
        {
          os << 'N';
        }
        else
        {
          os << queue[i]->val;
          queue.push_back(queue[i]->left);
          queue.push_back(queue[i]->right);
        }
      }
      return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      TreeNode* root = NULL;
      vector<string> slice = Split(data, ",");
      vector<TreeNode**> queue;
      queue.push_back(&root);
      for(size_t i = 0; i < slice.size(); i++)
      {
        if (slice[i].size() == 1u && slice[i][0] == 'N')
        {
          *queue[i] = NULL;
        }
        else
        {
          istringstream is(slice[i]);
          int val;
          is >> val;
          TreeNode* n = new TreeNode(val);
          *queue[i] = n;
          queue.push_back(&(n->left));
          queue.push_back(&(n->right));
        }
      }
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
class Solution
{
public:

};

int main()
{

  return 0;
}
