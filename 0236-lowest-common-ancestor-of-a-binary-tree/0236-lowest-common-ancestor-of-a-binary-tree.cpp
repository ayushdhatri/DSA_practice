/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* path(TreeNode* root, int a, int b)
    {
        if(root==NULL)
            return NULL;
        if(root->val==a||root->val==b)
            return root;
        TreeNode* left = path(root->left, a, b);
        TreeNode* right = path(root->right, a, b);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val;
        int b = q->val;
        return path(root, a, b);
        
    }
};