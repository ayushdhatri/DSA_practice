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
    bool calculate(TreeNode* root)
    {
        if(root==NULL)
            return true;
        bool leftevl = calculate(root->left);
        bool rightevl = calculate(root->right);
        
        if(root->val==0)
            return false;
        else if(root->val==1)
            return true;
        else if(root->val == 2)
            return leftevl||rightevl;
        return leftevl&&rightevl;
    }
    bool evaluateTree(TreeNode* root) {
        return calculate(root);
       
        
        
        
        
    }
};