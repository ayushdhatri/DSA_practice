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
    int postorder(TreeNode* root, int &maxans)
    {
        if(root==NULL)
            return 0;
        int leftsum = postorder(root->left, maxans);
        int rightsum = postorder(root->right, maxans);
        if(leftsum<0)
                leftsum = 0;
        if(rightsum<0)
                rightsum = 0;
        int currsum = leftsum+rightsum+root->val;
        maxans  = max(maxans, max(root->val, currsum));
        return root->val+max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxans = INT_MIN;
        int x  = postorder(root, maxans);
        maxans = max(x, maxans);
        return maxans;
        
        
        
        
    }
};