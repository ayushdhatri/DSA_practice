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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int leftmost = root->val;
        while(q.size()!=0)
        {
            int len = q.size();
            bool flag = true;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                if(flag)
                {
                    leftmost = curr->val;
                    flag = false;
                }
                
            }
            
        }
        return leftmost;
        
    }
};