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
    void preorder(TreeNode* root, string asf, vector<string>&ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            ans.push_back(asf+to_string(root->val));
            return;
        }
        
        string temp = to_string(root->val)+"->";
        preorder(root->left, asf+temp, ans);
        preorder(root->right, asf+temp, ans);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string asf="";
        vector<string>ans;
        preorder(root, asf, ans);
        return ans;
        
    }
};