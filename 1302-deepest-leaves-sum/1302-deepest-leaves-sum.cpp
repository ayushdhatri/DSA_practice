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
    int way1(TreeNode* root)
    {
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
    int maxdepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);
        return 1+max(lh, rh);
    }
    void inorder(TreeNode* root, int &sum, int currdepth, int depth)
    {
        if(root==NULL)
            return;
        if(currdepth==depth)
            sum+=root->val;
        inorder(root->left, sum, currdepth+1, depth);
        inorder(root->right, sum, currdepth+1, depth);
    }   
        
    int way2(TreeNode* root)
    {
        int depth=0;
        depth = maxdepth(root);
        int sum=0;
        inorder(root, sum,1,depth);
        return sum;
        
        

    }
    int deepestLeavesSum(TreeNode* root) {
        return way2(root);
       
    }
};