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
    void inorder(TreeNode* root, vector<int>&in)
    {
        if(root==NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>in;
        inorder(root, in);
        int mindiff = INT_MAX;
        for(int i=1;i<in.size();i++)
        {
            mindiff = min(mindiff, in[i]-in[i-1]);
        }
        return mindiff;
        
        
    }
};