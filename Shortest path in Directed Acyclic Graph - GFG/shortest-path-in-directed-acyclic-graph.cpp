//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>dist(N, INT_MAX);
        vector<pair<int, int>>adj[N];
        for(int i= 0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v, d});
        }
        queue<pair<int, int>>q;
        q.push({0, 0});
        dist[0]=0;
        while(q.size()!=0){
            int node = q.front().first;
            int distt = q.front().second;
            q.pop();
            for(auto x: adj[node]){
                int adj_node = x.first;
                int adj_dist = x.second;
                if(distt+adj_dist<dist[adj_node]){
                    dist[adj_node] = distt + adj_dist;
                    q.push({adj_node, dist[adj_node]});
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