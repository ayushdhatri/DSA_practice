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
    pair<int, int> countnodes(TreeNode* root, int &suchnodes)
    {
        if(root==NULL)
            return {0,0};
        auto left = countnodes(root->left, suchnodes);
        int leftsum = left.first;
        int leftcount = left.second;
        auto right = countnodes(root->right, suchnodes);
        int rightsum = right.first;
        int rightcount = right.second;
        int sum = leftsum+rightsum+root->val;
        int cnt = leftcount+rightcount+1;
        if(root->val==(round(sum/cnt)))
            suchnodes++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int suchnodes=0;
        countnodes(root,suchnodes);
        return suchnodes;
    }
};