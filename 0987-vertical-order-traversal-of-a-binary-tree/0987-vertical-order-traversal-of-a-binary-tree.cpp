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
void inorder(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>&verticalOrder){
    if(root == NULL)return;
    inorder(root->left, row+1,col-1, verticalOrder);
    verticalOrder[col].push_back({row, root->val});
    inorder(root->right, row+1,col+1, verticalOrder);
}
static bool comp(pair<int, int> &a, pair<int, int>&b){
    if(a.first < b.first){
        return true;
    }
    else if(a.first == b.first){
        // means same row same col
        if(a.second < b.second)return true;
    }
    return false;
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // we can associate each column with a value, which tells that a node belongs to which line
        // inorder traversal
        map<int, 
        vector<pair<int, int>>
        >verticalOrder;
        inorder(root,0,0,verticalOrder);
        vector<vector<int>>ans;
        for(auto x: verticalOrder){
            vector<pair<int, int>> currVerticalOrder = x.second;
            sort(currVerticalOrder.begin(), currVerticalOrder.end(), comp);
            vector<int>temp;
            for(auto x: currVerticalOrder){
                temp.push_back(x.second);
            }
            ans.push_back(temp);
        }
        return ans;

    

        
    }
};