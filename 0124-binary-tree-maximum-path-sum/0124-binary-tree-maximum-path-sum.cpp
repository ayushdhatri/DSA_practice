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
    int findheight(TreeNode* root, int &maxsum){
        if(root==NULL)
            return 0;
        int leftsum = findheight(root->left, maxsum);
        if(leftsum<0)
            leftsum=0;
        int rightsum = findheight(root->right, maxsum);
        if(rightsum<0)
            rightsum = 0;
        int currsum = root->val+leftsum+rightsum;
        maxsum = max(maxsum,currsum);
        return max(leftsum, rightsum)+root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxsum = max(maxsum,findheight(root, maxsum));
        return maxsum;
        
    }
};