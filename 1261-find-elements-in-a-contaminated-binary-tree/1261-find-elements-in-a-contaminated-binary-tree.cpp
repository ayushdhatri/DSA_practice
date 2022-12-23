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
    TreeNode* copyroot;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        int currvalue = root->val;
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
        copyroot = root;
        
        
    }
    bool dhundo(TreeNode* copyroot,int target)
    {
        if(copyroot==NULL)
            return false;
        if(copyroot->val==target)
            return true;
        bool leftside = dhundo(copyroot->left, target);
        bool rightside = dhundo(copyroot->right, target);
        return leftside||rightside;
    }
    bool find(int target) {
        return dhundo(copyroot, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */