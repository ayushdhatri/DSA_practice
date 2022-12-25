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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int len = q.size();
            vector<int>level;
            for(int i=0;i<len;i++)
            {
                TreeNode* currnode = q.front();
                q.pop();
                level.push_back(currnode->val);
                if(currnode->left!=NULL)
                    q.push(currnode->left);
                if(currnode->right!=NULL)
                    q.push(currnode->right);
                
            }
            int maxele = *max_element(level.begin(), level.end());
            ans.push_back(maxele);
        }
        return ans;
        
    }
};