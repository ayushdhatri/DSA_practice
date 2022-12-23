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
    void nodes(TreeNode* root, int maxSoFar, int &count)
    {
        if(root==NULL)
            return;
        int currnode = root->val;
        if(currnode>=maxSoFar)
        {
            count++;
            maxSoFar = currnode;
        }
        nodes(root->left, maxSoFar, count);
        nodes(root->right, maxSoFar, count);
    }
    int goodNodes(TreeNode* root) {
        int maxSoFar = INT_MIN;
        int count=0;
        nodes(root, maxSoFar, count);
        return count;
        
        
    }
};