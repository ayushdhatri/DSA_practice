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
    
    void sum(TreeNode* root, string temp,int &ans)
    {
        if(root==NULL)
            return;
           if(root->left==NULL&&root->right==NULL)
           {
               temp+=to_string(root->val);
               ans = ans + stoi(temp, 0, 2);
               return;
           }
            
            sum(root->left, temp+to_string(root->val), ans);
            sum(root->right, temp+to_string(root->val), ans);
            
        
       
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        string temp ="";
        sum(root, temp,ans);
        return ans;
        
    }
};