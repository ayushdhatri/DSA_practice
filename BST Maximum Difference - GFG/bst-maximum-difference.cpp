//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void findnode(Node* root, int target, Node* &target_node,int &sum)
    {
        if(root!=NULL)
        {
            if(root->data==target)
            {
                target_node = root;
                return;
            }
            else if(root->data>target){
            sum=sum+root->data;
            findnode(root->left, target, target_node,sum);
            }
            else{
                sum=sum+root->data;
                findnode(root->right, target, target_node,sum);
            }
        }
    }
    int findsum(Node* root)
    {
        if(root->left==NULL&&root->right==NULL)return root->data;
        else if(root->left==NULL)
        {
            return root->data+findsum(root->right);
        }else if(root->right==NULL)
        {
            return root->data+findsum(root->left);
        }
        int lsum = findsum(root->left);
        int rsum = findsum(root->right);
        return root->data + min(lsum, rsum);
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        Node* target_node = NULL;
        int a=0;
        findnode(root, target, target_node,a);
        if(target_node==NULL)return -1;
        int b = 0;
        int dataue = target_node->data;
        if(target_node==NULL) return a;
        b=findsum(target_node);
        
        b-=dataue;
        
        return a-b;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends