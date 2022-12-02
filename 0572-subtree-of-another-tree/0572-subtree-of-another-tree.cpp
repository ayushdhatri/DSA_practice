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
    bool identical(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL&&subRoot==NULL)
            return true;
        if(root==NULL||subRoot==NULL)
            return false;
        bool lefttree = identical(root->left, subRoot->left);
        bool righttree = identical(root->right, subRoot->right);
        return (root->val==subRoot->val)&&lefttree&&righttree;
    }
    bool preorder(TreeNode* root, TreeNode* subRoot)
    {
        if(root!=NULL) {
            bool ans = false;
            if(root->val==subRoot->val)
            {
                ans =  identical(root, subRoot);
            }
            if(ans==true)
                return true;
            bool lsubtree = preorder(root->left, subRoot);
            bool rsubtree = preorder(root->right, subRoot);
            return lsubtree||rsubtree;
        }
        return false;
            
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorder(root, subRoot);
      
        
        
        
    }
};