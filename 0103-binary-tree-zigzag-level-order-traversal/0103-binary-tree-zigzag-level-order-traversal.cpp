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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        bool ltr = true;
        queue<TreeNode*>dq;
        dq.push(root);
        while(dq.size()!=0)
        {
            int len = dq.size();
            vector<int>level;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = dq.front();
                level.push_back(curr->val);
                dq.pop();
                if(curr->left!=NULL)dq.push(curr->left);
                if(curr->right!=NULL)dq.push(curr->right);
                
            }
            if(ltr)
            {
                ans.push_back(level);
                ltr=false;
            }
            else
            {
                reverse(level.begin(), level.end());
                ans.push_back(level);
                ltr = true;
            }
        }
        
        return ans;
        
    }
};