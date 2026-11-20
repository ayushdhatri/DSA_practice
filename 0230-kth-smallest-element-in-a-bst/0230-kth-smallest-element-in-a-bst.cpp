/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
void inorder(TreeNode* node, int &curr, int k, int &kthElement){
    if(node != NULL){
        if(kthElement == -1)inorder(node->left, curr, k, kthElement);
        curr+=1;
        if(curr == k){
            kthElement = node->val;
            return;
        }
        if(kthElement == -1)inorder(node->right, curr, k, kthElement);
    }
}
    int kthSmallest(TreeNode* root, int k) {
        int curr = 0;
        int kthElement = -1;
        inorder(root, curr, k, kthElement);
        return kthElement;
    }
};