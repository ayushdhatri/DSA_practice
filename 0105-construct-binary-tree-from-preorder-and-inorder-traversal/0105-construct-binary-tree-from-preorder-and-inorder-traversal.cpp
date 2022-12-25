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
    TreeNode* construct(vector<int>&preorder, vector<int>&inorder, int presi, int preei, int insi, int inei)
    {
        if(presi>preei||insi>inei)
            return NULL;
        int element = preorder[presi];
        TreeNode* rootnode = new TreeNode(element);
        int index=0;
        for(index;index<inorder.size();index++)
        {
            if(inorder[index]==element)
                break;
        }
        int toteleinleftsubtree = index-insi;//correct
        int lspresi = presi+1;//correct
        int lspreei = presi+toteleinleftsubtree;//correct
        int lsinsi = insi;//
        int lsinei = index-1;
        int rspresi = lspreei+1;
        int rspreei = preei;
        int rsinsi = index+1;
        int rsinei = inei;
        TreeNode* leftsubtree = construct(preorder, inorder, lspresi, lspreei, lsinsi, lsinei);
        TreeNode* rightsubtree = construct(preorder, inorder, rspresi, rspreei, rsinsi, rsinei);
        rootnode->left = leftsubtree;
        rootnode->right = rightsubtree;
        return rootnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        int presi = 0;
        int preei = n-1;
        int insi = 0;
        int inei = m-1;
        return construct(preorder, inorder,presi, preei, insi, inei);
        
        
    }
};