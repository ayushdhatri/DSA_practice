class Solution {
public:
struct DSU{
    int n, *par, *rank;
    DSU(){}
    DSU(int totalNodes){
        this->n = totalNodes;
        this->par = new int[n];
        this->rank = new int[n];
        for(int i = 0;i<n;i++){
            par[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node){
        if(par[node] == node)return node;
        return par[node] = find(par[node]);//we are doing path compression

    }

    void merge(int nodeX, int nodeY){
        int rootX = find(nodeX);
        int rootY = find(nodeY);
        if(rootX == rootY)return;
        if(rank[rootX] >= rank[rootY]){// here we do rank compression
            rank[rootX] += rank[rootY];
            par[rootY] = rootX;
        }
        else{
            rank[rootY] += rank[rootX];
            par[rootX] = rootY;
        }
    }


};
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
        DSU dsu(n);
        for(int i = 0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            dsu.merge(u, v);
        }
        int rootX = dsu.find(source);
        int rootY = dsu.find(destination);
        if(dsu.find(source) == dsu.find(destination))return true;
        return false;

        // return usingDFS(source, destination, visited, adj);
    
        
        
    }
};