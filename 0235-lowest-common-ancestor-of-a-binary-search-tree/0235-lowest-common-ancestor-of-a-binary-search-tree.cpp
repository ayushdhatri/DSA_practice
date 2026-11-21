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
/*
Brute Force:
- Start from the root
- Check if a node is ancestory or not
- It is ancestor only if you can reach two nodes p and q from that node;
- You mark it and , we need a depth to mark 
- if(a node is ancestor && currDepth < depth){
     // update it
}

Optimize:
For  node p  start traversing upwards and store the path.
For node q start traversing upward and check if that node is present in othe path or not
If present we can return that the node present in the LCA
Tc : O(N) worst case in case of skew tree else O(h) where h is the height of tree.
Sc: O(N) since we are storing it in map so worst it can go is O(N)

In Case of BST:
- We can say that what values will be on the right subtree and on the left subtree
//

*/
void findLCAOfNodePAndQ(TreeNode* root, int valueOfP, int valueOfQ, TreeNode* &p){

    int rootValue = root->val;
    //cout<<"Lets decide for rootValue"<<rootValue<<endl;
    if(valueOfP < rootValue && valueOfQ > rootValue ){
        // both lie on two different subtree hence root will be one ancestor
        p = root;
       // cout<<"Ancestor decided "<<p->val<<" As anestor"<<endl;
        return;
    }
    if(valueOfP < rootValue && valueOfQ < rootValue){
        // both lie on leftSubTree
        // so here I need to think if 
        p = root;
       // cout<<"Going Left and mark "<<p->val<<" As anestor"<<endl;
        findLCAOfNodePAndQ(root->left, valueOfP, valueOfQ, p);
    }
    else if(valueOfP > rootValue && valueOfQ > rootValue){
        // both lie on rightSubTree
        // mark this node as current ancestor because it is one suhc ansestor
        p = root;
       // cout<<"Going right and mark "<<p->val<<" As anestor"<<endl;
        findLCAOfNodePAndQ(root->right, valueOfP, valueOfQ, p);
    }
    else if(rootValue == valueOfP || root->val == valueOfQ){

        p = root;
        //cout<<"For skew tree :  "<<p->val<<" As anestor"<<endl;
        return;
    }
   
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCA = root;
        if(root->val == q->val || root->val == p->val)return root;
        int valueOfP = p->val;
        int valueOfQ = q->val;
        if(valueOfP > valueOfQ){
            swap(valueOfP, valueOfQ);
        }
        //findLCAOfNodePAndQ(root, valueOfP, valueOfQ ,LCA);
        TreeNode* curr = root;
        
        while(curr != NULL){
            if(valueOfQ < curr->val){
                // go to left
                curr = curr->left;
            }
            else if(valueOfP > curr->val){
                curr = curr->right;
            }
            else{
                return curr;
            }

        }
        return NULL;

        
    }
};