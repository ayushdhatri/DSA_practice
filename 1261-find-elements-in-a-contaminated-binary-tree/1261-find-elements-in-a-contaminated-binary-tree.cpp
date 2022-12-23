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
class FindElements {
public:
    unordered_set<int>elements;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        int currvalue = root->val;
        elements.insert(currvalue);
        if(root->left!=NULL)
            root->left->val = 2*currvalue+1;
        if(root->right!=NULL)
            root->right->val = 2*currvalue+2;
        inorder(root->left);
        inorder(root->right);
    }
    FindElements(TreeNode* root) {
        root->val=0;
        inorder(root);
        
        
        
    }
    
    bool find(int target) {
        if(elements.find(target)==elements.end())
            return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */