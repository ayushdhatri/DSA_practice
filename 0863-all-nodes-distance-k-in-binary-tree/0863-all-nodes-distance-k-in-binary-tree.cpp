/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void preorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent,unordered_map<TreeNode*, bool>&visited){
    if(root != NULL){
        visited[root] = false;
        if(root->left != NULL){
            parent[root->left] = root;
        }
        if(root->right != NULL){
            parent[root->right] = root;
        }
        preorder(root->left, parent, visited);
        preorder(root->right, parent, visited);

    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // we need to build the parent-chlid relationship
        // if(root->left == NULL && root->right == NULL){
        //     return {root->val};
        // }
        unordered_map<TreeNode*, TreeNode*> parent;// it defines for a node what is it's parent
        parent[root] = NULL;
        unordered_map<TreeNode*, bool> visited;
        preorder(root, parent, visited);//

        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited[target] = true;
        vector<int>ans;
        while(q.size() != 0){
            TreeNode* node = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            if(currLevel == k){
                ans.push_back(node->val);
            }
            else if(currLevel > k){
                break;
            }
            // traverse to left, child and parent if not visited
            if(node->left != NULL && visited[node->left] == false){
                visited[node->left] = true;
                q.push({node->left, currLevel + 1});
            }
            if(node->right != NULL && visited[node->right] == false){
                visited[node->right] = true;
                q.push({node->right, currLevel + 1});
            }
            if(parent[node] != NULL && visited[parent[node]] == false){
                visited[parent[node]] = true;
                q.push({parent[node], currLevel + 1});
            }


        }
        return ans;


        

    }
};