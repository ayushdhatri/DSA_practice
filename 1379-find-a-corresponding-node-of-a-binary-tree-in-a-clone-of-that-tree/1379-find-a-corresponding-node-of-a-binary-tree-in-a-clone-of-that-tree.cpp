/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* root, int a, TreeNode* &k)
    {
        if(root!=NULL)
        {
            if(root->val == a)
            {
                k = root;
                return;
            }
            inorder(root->left, a, k);
            inorder(root->right, a, k);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int a = target->val;
        TreeNode* k = NULL;
        inorder(cloned, a, k);
        return k;
        
        
    }
};