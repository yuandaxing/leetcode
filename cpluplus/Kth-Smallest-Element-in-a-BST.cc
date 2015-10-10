/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  int findKSmallest(TreeNode* root, int& result, int K)
  {
    if(root == NULL)
      return 0;
    int left = findKSmallest(root->left, result, K);
    if(left + 1 > K)
      return left + 1;
    else if (left + 1 == K)
    {
      result = root->val;
      return left + 1;
    } else
    {
      return findKSmallest(root->right, result, K - left - 1) + left + 1;
    }
  }
  int kthSmallest(TreeNode* root, int k)
  {
    int result = 0;
    findKSmallest(root, result, k);
    return result;
  }
};
