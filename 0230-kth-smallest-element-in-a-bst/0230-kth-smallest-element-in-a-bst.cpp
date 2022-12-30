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
    void inorder(TreeNode* root,int &ans, int &count,int k)
    {
        if(root==NULL)
            return;
        
        inorder(root->left, ans, count,k);
        count++;
        if(count==k)
            ans = root->val;
        inorder(root->right, ans, count,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MIN;
        int count=0;
        inorder(root, ans, count,k);
        return ans;
        
        
    }
};