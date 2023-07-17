//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void build_parent(Node* root, unordered_map<Node* , Node*>&parent, Node* &target_node, int target,unordered_map<Node* , bool>&visited)
  {
      if(root==NULL)return;
      if(root->left!=NULL)parent[root->left]=root;
      if(root->right!=NULL)parent[root->right]=root;
      if(root->data ==target){
          target_node=root;
      }
      visited[root]=false;
      build_parent(root->left, parent,target_node, target, visited);
      build_parent(root->right, parent,target_node, target, visited);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node* ,Node* >parent;
        parent[root]=NULL;
        Node* target_node = NULL;
        unordered_map<Node*, bool>visited;
        build_parent(root, parent,target_node, target, visited);
        queue<pair<Node* , int>>q;
        q.push({target_node, 0});
        visited[target_node]=true;
        int ans = -1;
        while(q.size()!=0){
            int len = q.size();
            for(int i = 0;i<len;i++){
                Node* curr_node = q.front().first;
                int curr_time = q.front().second;
                ans = max(ans, curr_time);
                q.pop();
                if(curr_node->left!=NULL&&visited[curr_node->left]==false){
                    visited[curr_node->left]=true;
                    q.push({curr_node->left, curr_time+1});
                }
                if(curr_node->right!=NULL&&visited[curr_node->right]==false){
                    visited[curr_node->right]=true;
                    q.push({curr_node->right, curr_time+1});
                }
                if(parent[curr_node]!=NULL&&visited[parent[curr_node]]==false){
                    visited[parent[curr_node]]=true;
                    q.push({parent[curr_node],curr_time+1});
                }
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends