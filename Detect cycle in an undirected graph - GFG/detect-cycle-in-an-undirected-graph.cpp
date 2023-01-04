//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int vertex, vector<bool>&visited, vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({vertex, -1});
        visited[vertex]=true;
        while(q.size()!=0)
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                pair<int, int>curr = q.front();
                q.pop();
                int currver = curr.first;
                int currpar = curr.second;
                for(auto x: adj[currver])
                {
                    if(visited[x]==true)
                    {
                        if(x!=currpar)
                            return true;
                    }
                    else
                    {
                        visited[x]=true;
                        q.push({x, currver});
                    }
                }
               
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
         vector<bool>visited(V, false);
         int ans = false;
         for(int i=0;i<V;i++)
         {
             if(visited[i]==false){
                 int temp = bfs(i,visited, adj);
                 if(temp==true)
                 return true;
             }
         }
         return false;
        
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