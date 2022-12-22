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
        vector<int>arr;
        inorder(root,arr);
        int n = arr.size();
        long long int first, second;
        first = second = 1e14;
        for (int i = 0; i<n; i++)
        {
            if (arr[i] < first)
            {
                second = first;
                first = arr[i];
            }
            else if (arr[i] < second && arr[i] != first)
                second = arr[i];
        }
        if(second == 1e14)
            return -1;
        return second;

        
        
        
    }
};