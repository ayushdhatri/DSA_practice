//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int vertex, vector<int>adj[], vector<bool>&visited, vector<bool>&path_visited){
        visited[vertex]=true;
        path_visited[vertex]=true;
        for(auto x: adj[vertex])
        {
            if(visited[x]==true){
                if(path_visited[x]==true)return true;
            }
            else{
                bool temp = dfs(x, adj, visited, path_visited);
                if(temp==true)return true;
            }
        }
        path_visited[vertex]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false);
        vector<bool>path_visited(V, false);
        for(int i= 0;i<V;i++){
            if(visited[i]==false){
                bool temp = dfs(i, adj, visited, path_visited);
                if(temp==true)return true;
            }
        }
        return false;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends