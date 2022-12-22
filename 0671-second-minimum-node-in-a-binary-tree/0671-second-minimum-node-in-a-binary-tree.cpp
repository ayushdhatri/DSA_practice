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
    void inorder(TreeNode* root, vector<int>&nodes)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            nodes.push_back(root->val);
            return;
        }
        nodes.push_back(root->val);
        inorder(root->left, nodes);
        inorder(root->right, nodes);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int>nodes;
        inorder(root, nodes);
        sort(nodes.begin(), nodes.end());
        int minnvalue = nodes[0];
        int i=1;
        int n = nodes.size();
        while(i<n&&nodes[i]<=minnvalue)
        {
            i++;
        }
        if(i==n)
            return -1;
        return nodes[i];
        
        
        
        
        
    }
};