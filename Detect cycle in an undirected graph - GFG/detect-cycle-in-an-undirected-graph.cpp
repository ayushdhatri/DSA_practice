//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int vertex, vector<bool>&visited, vector<int>adj[]){
        queue<pair<int, int>>q;
        visited[vertex]=true;
        q.push({vertex, -1});
        while(q.size()!=0){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto adjnode: adj[node]){
                if(visited[adjnode]==false){
                    visited[adjnode]=true;
                    q.push({adjnode, node});
                }
                else{
                    if(adjnode!=par){
                        return true;
                    }
                }
                
            }
            
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V, false);
        bool ans = false;
        for(int i = 0;i<V;i++){
            if(visited[i]==false){
                bool temp = bfs(i, visited, adj);
                ans = ans||temp;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends