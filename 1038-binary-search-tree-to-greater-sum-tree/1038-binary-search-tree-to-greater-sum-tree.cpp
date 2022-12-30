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
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ls = sum(root->left);
        int rs = sum(root->right);
        return root->val+ls+rs;
    }
    void inorder(TreeNode* root, int &lts, int totalsum)
    {
        if(root!=NULL)
        {
            inorder(root->left, lts, totalsum);
            int nodevalue = totalsum-lts-root->val;
            lts+=root->val;
            root->val = nodevalue+root->val;
            inorder(root->right, lts, totalsum);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int totalsum = 0;
        totalsum = sum(root);
        cout<<totalsum;
        int lts = 0;
        inorder(root,lts,totalsum);
        return root;
        
    }
};