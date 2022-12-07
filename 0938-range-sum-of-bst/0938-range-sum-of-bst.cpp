class Solution {
public:
    int rangeSumBST(TreeNode* root, int l, int h) {
         return root==NULL  ?  0  :   ((root->val>h || root->val<l)? 0 : root->val)   +   rangeSumBST(root->left,l,h)  +  rangeSumBST(root->right,l,h);
    }
};