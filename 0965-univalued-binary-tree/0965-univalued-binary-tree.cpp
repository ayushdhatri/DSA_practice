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
    bool preorder(TreeNode* root, int data)
    {
        if(root==NULL)
            return true;
        bool leftcheck = preorder(root->left,data);
        bool rightcheck = preorder(root->right,data);
        return (root->val==data)&&leftcheck&&rightcheck;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        int a = root->val;
        return preorder(root, a);
        
        
    }
};