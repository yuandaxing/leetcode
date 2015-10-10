/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* Helper(TreeNode* parent, TreeNode*& right)
    {
        if(parent->left == NULL)
        {
            right = parent;
            return parent;
        }
        TreeNode* newRight;
        TreeNode* ret = Helper(parent->left, newRight);
        newRight->left = parent->right;
        newRight->right = parent;
        right = parent;
        right->left = NULL;
        right->right = NULL;
        return ret;
    }

    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(NULL == root) {return NULL;}
        TreeNode* tmp;
        return Helper(root, tmp);
    }
};
