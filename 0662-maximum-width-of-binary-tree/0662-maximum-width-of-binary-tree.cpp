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
    int widthOfBinaryTree(TreeNode* root) {
          if(root==NULL)
              return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        long long  int ans=0;
        while(q.size()!=0)
        {
            long long  int len = q.size();
            long long int minwid=INT_MAX;
            long long  int maxwid = INT_MIN;
          
            for(int i=0;i<len;i++)
            {
                TreeNode* curr = q.front().first;
                long long int index = q.front().second;
                q.pop();
                minwid=min(minwid, index);
                maxwid = max(maxwid, index);
                int li = 2*index+1;
                int ri = 2*index+2;
                if(curr->left!=NULL)q.push({curr->left, li});
                if(curr->right!=NULL)q.push({curr->right, ri});
            }
            ans = max(ans, maxwid-minwid+1);
            
            
        }
        return ans;
            
        
       
        
    }
};