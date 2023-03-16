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
    void buildparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&freq, unordered_map<TreeNode*, bool>&visited)
    {
        if(root!=NULL)
        {
            if(root->left!=NULL){
                freq[root->left]=root;
            }
            if(root->right!=NULL)
                freq[root->right]=root;
            visited[root]=false;
            buildparent(root->left, freq, visited);
            buildparent(root->right, freq,visited);
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // if i can do level order traversal in all direction then i can do this question very easeily
        // so basically i need a parent for each element;
        // basically each node will have parent
        
        unordered_map<TreeNode*, TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited;
        
        parent[root]=NULL;
        buildparent(root, parent,visited);
        // we can do bfs simple
        queue<TreeNode*>q;
        q.push(target);
        vector<int>ans;
        int currlevel = 0;
        visited[target]=true;
        while(q.size()!=0)
        {
            
            int len = q.size();
            if(currlevel++==k){break;
                
            }
            for(int i=0;i<len;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL&&visited[curr->left]==false)
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right!=NULL&&visited[curr->right]==false){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr]!=NULL&&visited[parent[curr]]==false)
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
            
            
        }
        while(q.size()!=0)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
        
        
        
    }
};