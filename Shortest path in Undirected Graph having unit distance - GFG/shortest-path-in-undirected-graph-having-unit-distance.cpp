//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>dist(N, INT_MAX);
        vector<int>adj[N];
        for(int i = 0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(N, false);
        queue<int>q;
        q.push(src);
        visited[src]=true;
        dist[src]=0;
        while(q.size()!=0){
            int curr_node = q.front();
            q.pop();
            for(auto adj_node: adj[curr_node]){
                if(visited[adj_node]==false){
                    visited[adj_node]=true;
                    if(dist[curr_node]+1<dist[adj_node]){
                        dist[adj_node]=dist[curr_node]+1;
                    }
                    q.push(adj_node);
                }
                
            }
        }
        for(int i = 0;i<N;i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends