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
    void nodes(TreeNode* root, vector<int>path, int &count)
    {
        if(root==NULL)
            return;
        int currnode = root->val;
        path.push_back(currnode);
        bool include = true;
        for(auto x: path)
        {
            if(x>currnode) {
                include = false;
                break;
            }
        }
        if(include)
            count++;
        nodes(root->left, path, count);
        nodes(root->right, path, count);
    }
    
    int goodNodes(TreeNode* root) {
        vector<int>path;
        int count=0;
        nodes(root, path, count);
        return count;
        
        
    }
};