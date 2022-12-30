/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool valid(TreeNode* root, long long int lr, long long int rr)
    {
        if(root==NULL)
            return true;
        bool isvalidnode = false;
        if(root->val<rr&&root->val>lr)
            isvalidnode = true;
        return isvalidnode&&valid(root->left, lr, root->val)&&valid(root->right,root->val, rr);
        
        
        
    }
    bool isValidBST(TreeNode* root) {
        // if(root->left==NULL&&root->right==NULL)
        //     return true;
        long long int lr = -1e14;
        long long int rr = 1e14;
        return valid(root, lr, rr);
        
    }
};