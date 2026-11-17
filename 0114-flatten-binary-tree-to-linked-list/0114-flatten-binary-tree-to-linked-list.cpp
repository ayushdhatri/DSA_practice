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
// root -> left-> right
// we need two pointer
// head and tail for each of the subtree
// once we have two things for left and right subtree to get final singely linked list 
// root->right = left_head;
// left_tail->next = right_head;
// return root; 
pair<TreeNode*, TreeNode*> convert(TreeNode* root){
    if(root == NULL)return {NULL, NULL};
    if(root->left == NULL && root->right == NULL){
        return {root, root};
    }
    pair<TreeNode*, TreeNode*> leftSubTreeLinkedList = convert(root->left);
    pair<TreeNode*, TreeNode*> rightSubTreeLinkedList = convert(root->right);
    root->right = leftSubTreeLinkedList.first == NULL? rightSubTreeLinkedList.first : leftSubTreeLinkedList.first;
    root->left = NULL;
    if(leftSubTreeLinkedList.second != NULL){
        leftSubTreeLinkedList.second->right = rightSubTreeLinkedList.first;
        leftSubTreeLinkedList.second->left = NULL;
    }
    if(rightSubTreeLinkedList.first != NULL){
        rightSubTreeLinkedList.first->left = NULL;
    }
    if(rightSubTreeLinkedList.second != NULL){
        rightSubTreeLinkedList.second->right = NULL;
    }

    TreeNode* headOfLinkedList = root;
    TreeNode* tailOfLinkedList = root;
    if(leftSubTreeLinkedList.second != NULL){
        tailOfLinkedList = leftSubTreeLinkedList.second;
    }
    if(rightSubTreeLinkedList.second != NULL){
        tailOfLinkedList = rightSubTreeLinkedList.second;
    }
    return {headOfLinkedList, tailOfLinkedList};
}
    void flatten(TreeNode* root) {
        convert(root);
        
    }
};