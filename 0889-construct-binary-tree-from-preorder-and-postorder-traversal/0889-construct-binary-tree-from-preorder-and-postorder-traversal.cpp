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
    TreeNode* construct(vector<int>&preorder, vector<int>&postorder, int presi, int preei, int posi, int poei)
    {
        if(presi>preei||posi>poei)
            return NULL;
        int element = preorder[presi];
        TreeNode* rootnode = new TreeNode(element);
        if(presi==preei)
            return rootnode;
        int lmelsubtree = preorder[presi+1];
        int index = 0;
        for(;index<postorder.size();index++)
        {
            if(postorder[index]==lmelsubtree)
                break;
        }
        int totalleftelement = index-posi+1;
        int lspresi = presi+1;
        int lspreei =presi+totalleftelement;
        int lsposi =  posi;
        int lspoei = index;
        int rspresi =lspreei+1 ;
        int rspreei =preei;
        int rsposi = index+1;
        int rspoei = poei-1;
        TreeNode* leftsubtree = construct(preorder, postorder, lspresi, lspreei, lsposi, lspoei);
        TreeNode* rightsubtree = construct(preorder, postorder, rspresi, rspreei, rsposi, rspoei);
        rootnode->left = leftsubtree;
        rootnode->right = rightsubtree;
        return rootnode;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int m = postorder.size();
        int presi = 0;
        int preei = n-1;
        int posi = 0;
        int poei = m-1;
        return construct(preorder, postorder, presi, preei, posi, poei);
        
        
        
    }
};