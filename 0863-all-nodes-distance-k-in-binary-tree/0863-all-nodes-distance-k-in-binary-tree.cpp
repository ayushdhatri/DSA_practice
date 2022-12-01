/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parenttraversal(TreeNode* root,unordered_map<TreeNode* , TreeNode*>&parent)// we construct parent of each node
    {
        if(root==NULL)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL)
                {
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    parent[curr->right]=curr;
                    q.push(curr->right);
                }
                
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent;
        parent[root]=NULL;
        parenttraversal(root, parent);
        int currlevel = 0;
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        while(q.size()!=0)
        {
            int len = q.size();
            if(currlevel++ == k)break;
            
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL&&visited[curr->left]==false)
                {
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right!=NULL&&visited[curr->right]==false)
                {
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr]!=NULL&&visited[parent[curr]]==false)
                {
                    visited[parent[curr]]=true;
                    q.push(parent[curr]);
                }
            }
            
        }
        vector<int>res;
        while(q.size()!=0)
        {
            TreeNode* curr = q.front();q.pop();
            res.push_back(curr->val);
        }
        return res;
        
        
        
        
        
        
    }
};