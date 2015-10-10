#include <stdlib.h>
#include <vector>
using std::vector;
/**
 * Definition for binary tree
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
class BSTIterator
{
public:
  // struct State
  // {
  //   TreeNode* e_;
  //   int state_;
  //   State(TreeNode* e, int state) :
  //     e_(e), state_(state)
  //   {
  //   }
  // };
  vector<TreeNode*> stack_;
  BSTIterator(TreeNode *root)
  {
    while (NULL != root)
    {
      stack_.push_back(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return !stack_.empty();
  }

  /** @return the next smallest number */
  int next()
  {
    TreeNode* cur = stack_.back(), *right = cur->right;
    stack_.pop_back();
    while (NULL != right)
    {
      stack_.push_back(right);
      right = right->left;
    }
    return cur->val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
