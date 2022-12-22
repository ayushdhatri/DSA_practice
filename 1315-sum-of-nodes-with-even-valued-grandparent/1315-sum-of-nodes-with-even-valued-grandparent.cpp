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
    void levelorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* currnode = q.front();
                q.pop();
                if(currnode->left!=NULL)
                {
                    q.push(currnode->left);
                    parent.insert({currnode->left,currnode});
                }
                if(currnode->right!=NULL)
                {
                    q.push(currnode->right);
                    parent.insert({currnode->right, currnode});
                }
            }
        }
    }
    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent, int &count)
    {
        if(root!=NULL)
        {
            
            TreeNode* par = parent[root];
            TreeNode* grandparent = NULL;
            if(par!=NULL)
            {
                grandparent = parent[par];
            }
            if(grandparent!=NULL&&grandparent->val%2==0)
                count+=root->val;
            inorder(root->left, parent, count);
            inorder(root->right, parent, count);
        }
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*>parent;
        levelorder(root, parent);
        int count=0;
        inorder(root, parent,count);
        return count;
        
        
        
        
        
    }
};