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
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int currlevelsum=0;
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* currnode = q.front();
                q.pop();
                currlevelsum+=currnode->val;
                if(currnode->left!=NULL)
                    q.push(currnode->left);
                if(currnode->right!=NULL)
                    q.push(currnode->right);
            }
            sum = currlevelsum;
        }
        return sum;
        
    }
};