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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*>q;
        stack<vector<int>>st;
        
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        q.push(root);
        while(q.size()!=0)
        {
            int len = q.size();
            vector<int>mid;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                mid.push_back(curr->val);
            }
            st.push(mid);
            
        }
         while(st.size()!=0)
        {
            ans.push_back(st.top());
            st.pop();
            
            
        }
        return ans;
        
    }
};