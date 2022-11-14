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
   void check(TreeNode* root1, TreeNode* root2, bool &ans)
   {
       if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL))
       {
           ans=false;
           return;
       }
       if(root1==NULL&&root2==NULL)
           return;
       if(root1->val!=root2->val)
           ans=false;
       check(root1->left, root2->right, ans);
       check(root1->right, root2->left, ans);
        
       
   }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL)
            return true;
        bool ans=true;
        check(root->left, root->right, ans);
        return ans;
       
    
        
    }
};