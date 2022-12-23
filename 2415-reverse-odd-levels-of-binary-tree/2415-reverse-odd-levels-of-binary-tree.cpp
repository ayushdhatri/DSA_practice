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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level =0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int len = q.size();
            vector<int>nextlevele;
            queue<TreeNode*>temp=q;
            for(int i=0;i<len;i++)
            {
                TreeNode* currnode = temp.front();
                temp.pop();
                if(currnode->left!=NULL)
                {
                    q.push(currnode->left);
                    nextlevele.push_back(currnode->left->val);
                }
                if(currnode->right!=NULL)
                {
                    q.push(currnode->right);
                    nextlevele.push_back(currnode->right->val);
                }
            }
            
            reverse(nextlevele.begin(), nextlevele.end());
            if(level%2==0) {
                int j=0;
                for(int i=0;i<len;i++)
                {
                    TreeNode* currnode = q.front();
                    q.pop();
                    if(currnode->left!=NULL)currnode->left->val=nextlevele[j++];
                    if(currnode->right!=NULL)currnode->right->val = nextlevele[j++];
                }
            }
            else
            {
                for(int i=0;i<len;i++)
                {
                    TreeNode* currnode = q.front();
                    q.pop();
                    
                }
                
            }
            level++;
        }
        return root;
        
        
        
    }
};