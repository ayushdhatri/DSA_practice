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
    int nodesum(TreeNode* root, int &nodes)
    {
        if(root==NULL)
            return 0;
        if(root!=NULL)
            nodes++;
        int leftsum = nodesum(root->left, nodes);
        int rightsum = nodesum(root->right, nodes);
        return leftsum+rightsum+root->val;
        
    }
    void countnodes(TreeNode* root, int &suchnodes)
    {
        if(root==NULL)
            return;
        int totalnode=0;
        int dessum = nodesum(root, totalnode);
        int avg = round(dessum/totalnode);
        if(avg==root->val)
            suchnodes++;
        countnodes(root->left, suchnodes);
        countnodes(root->right,suchnodes);
    }
    int averageOfSubtree(TreeNode* root) {
        int suchnodes=0;
        countnodes(root,suchnodes);
        return suchnodes;
        
        
        
        
    }
};