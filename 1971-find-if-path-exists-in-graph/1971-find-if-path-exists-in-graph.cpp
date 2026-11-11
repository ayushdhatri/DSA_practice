class Solution {
public:
    bool usingDFS(int node, int dest,vector<bool>&visited, vector<vector<int>>&adj){
        if(node == dest)return true;
        visited[node] = true;
        for(auto x: adj[node]){
            if(visited[x] == false){
                if(usingDFS(x, dest, visited, adj))return true;
            }
        }
        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();// number of edges
        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);
        for(int i = 0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return usingDFS(source, destination, visited, adj);
        
    }
};