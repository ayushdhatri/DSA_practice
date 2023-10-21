//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int index,int parent ,int V, vector<int>adj[], vector<bool>&visited, vector<bool>&path_visited)
    {
        visited[index]=true;
        path_visited[index]=true;
        for(auto x: adj[index]){
            if(visited[x]==true)
            {
                if(path_visited[x]==true)return true;
                
            }
            else{
                bool temp = dfs(x, index, V, adj, visited, path_visited);
                if(temp==true)return true;
            }
        }
        path_visited[index]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false);
        vector<bool>path_visited(V, false);
        bool flag = false;
        for(int i = 0;i<V;i++){
            if(visited[i]==false){
                bool temp = dfs(i, -1,V, adj, visited, path_visited);
                flag = flag||temp;
            }
        }
        return flag;
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