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
    TreeNode* traverse(TreeNode* root, int p, int q)
    {
        if(root==NULL)
            return NULL;
        if(root->val==p||root->val==q)
            return root;
        TreeNode* left = traverse(root->left, p, q);
        TreeNode* right = traverse(root->right, p, q);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
        return root;
    }
    
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return traverse(root, p->val, q->val);
      
        
        
        
        
        
    }
};