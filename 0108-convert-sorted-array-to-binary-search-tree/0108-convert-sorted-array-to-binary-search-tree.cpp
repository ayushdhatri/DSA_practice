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
TreeNode* convertToBst(int start, int end, vector<int>&nums){
    if(start > end)return NULL;

    int mid = start + (end - start)/2;
    int rootValue = nums[mid];
    TreeNode* root = new TreeNode(rootValue);
    TreeNode* leftSubTree = convertToBst(start, mid-1, nums);
    TreeNode* rightSubTree = convertToBst(mid+1, end, nums);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // we can always bisect from the middle choose the left half as left subtree and choose the right half
        // as right subtree
        int n = nums.size();
        int low = 0, high = n-1;
        return convertToBst(low, high, nums);
        
        
    }
};