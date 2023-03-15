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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        while(q.size()!=0)
        {
            vector<int>mid;
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                mid.push_back(curr->val);
            }
            ans.push_back(mid);
        }
        return ans;
        
    }
};