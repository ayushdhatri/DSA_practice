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
    TreeNode* construct(vector<int>&postorder, vector<int>&inorder, int posi, int poei, int insi, int inei)
    {
        if(posi>poei||insi>inei)
            return NULL;
        int element = postorder[poei];
        TreeNode* rootnode = new TreeNode(element);
        int index = 0;
        while(index<inorder.size())
        {
            if(inorder[index]==element)
                break;
            index++;
        }
        int toteleinrighttsubtree = inei-index;
        int rsposi = poei-toteleinrighttsubtree;
        int rspoei = poei-1;
        int rsinsi = index+1;
        int rsinei = inei;
        int lsposi =  posi;
        int lspoei = rsposi-1;
        int lsinsi = insi;
        int lsinei = index-1;
        TreeNode* leftsubtree = construct(postorder, inorder, lsposi, lspoei, lsinsi, lsinei);
        TreeNode* rightsubtree = construct(postorder, inorder, rsposi, rspoei, rsinsi, rsinei);
        rootnode->left = leftsubtree;
        rootnode->right = rightsubtree;
        return rootnode;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int m = inorder.size();
        int posi = 0;
        int poei = n-1;
        int insi = 0;
        int inei = m-1;
        return construct(postorder, inorder, posi, poei, insi, inei);
    }
};