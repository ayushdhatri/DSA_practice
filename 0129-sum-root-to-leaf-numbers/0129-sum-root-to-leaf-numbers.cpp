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
    void preorder(TreeNode* root, string asf, int &totalsum)
    {
          if(root==NULL)
              return ;
          if(root->left==NULL&&root->right==NULL)
            {
               asf+=to_string(root->val);
               totalsum+=stoi(asf);
              return;
            }
           asf+=to_string(root->val);
           preorder(root->left, asf, totalsum);
           preorder(root->right, asf, totalsum);
         
       

    }
    int sumNumbers(TreeNode* root) {
        int totalsum=0;
        string asf="";
        preorder(root, asf, totalsum);
        return totalsum;
        
    }
};