//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void toposort(int vertex, vector<bool>&visited, stack<int>&st, vector<pair<int, int>>adj[])
  {
      visited[vertex]=true;
      for(auto x: adj[vertex])
      {
          int node = x.first;
          if(visited[node]==false)
          {
              toposort(node, visited,st, adj);
          }
      }
      st.push(vertex);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>>adj[N];
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        vector<bool>visited(N, false);
        stack<int>st;
        for(int i=0;i<N;i++)
        {
            if(visited[i]==false)
            {
                toposort(i, visited, st, adj);
            }
        }
        vector<int>dist(N, INT_MAX);
        int src = 0;
        dist[src]=0;
        while(st.top()!=src)
        {
            st.pop();
        }
        
        
        while(st.size()!=0)
        {
            int node = st.top();
            st.pop();
            for(auto x: adj[node])
            {
                int adjnode = x.first;
                int weight = x.second;
                if(dist[node]+weight<dist[adjnode])
                {
                    dist[adjnode]=dist[node]+weight;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        return dist;
        
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends