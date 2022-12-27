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
    void inorder(TreeNode* root, vector<int>&it)
    {
        if(root==NULL)
            return;
     
        inorder(root->left, it);
        it.push_back(root->val);
        inorder(root->right, it);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int>it;
        inorder(root, it);
        int mindiff= INT_MAX;
        int first = it[0];
        for(auto x:it)
            cout<<x<<" ";
        cout<<endl;
        for(int i=1;i<it.size();i++)
        {
            mindiff = min(mindiff, it[i]-it[i-1]);
        }
        return mindiff;
        
    }
};