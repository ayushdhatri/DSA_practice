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
// Inorder  -> Left -> Root -> Right
// Preorder -> Root -> Left -> Right 
TreeNode* constructTree(int preLow, int preHigh, int inLow, int inHigh, vector<int>&preOrder, vector<int>&inOrder,
unordered_map<int, int>&indexMap){
    if(inLow > inHigh){
        return NULL;
    }
    TreeNode* root = new TreeNode(preOrder[preLow]);// rootNode
    int rootIndexInOrder = indexMap[root->val];
    // cout<<"Root value "<<root->val<<endl;
    // for(int i = inLow;i<=inHigh;i++){
    //     if(inOrder[i] == root->val){
    //         rootIndexInOrder = i;
    //         break;
    //     }
    // }
    int LenOfLeftSubTree = rootIndexInOrder - inLow;
    int LenOfRightSubTree = inHigh - rootIndexInOrder;
    root->left = constructTree(preLow + 1, preLow + LenOfLeftSubTree - 1, inLow, rootIndexInOrder - 1, preOrder, inOrder,indexMap);
    root->right = constructTree(preLow + LenOfLeftSubTree + 1, preHigh, rootIndexInOrder + 1, inHigh, preOrder, inOrder,indexMap);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preLow = 0, preHigh = n-1, inLow = 0, inHigh = n-1;
        unordered_map<int, int>indexMap;
        for(int i = 0;i<inorder.size();i++){
            indexMap[inorder[i]] = i;
        }
        return constructTree(preLow, preHigh, inLow, inHigh, preorder, inorder, indexMap);

        
    }
};