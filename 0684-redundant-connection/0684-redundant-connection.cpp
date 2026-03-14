class Solution {
public:
struct DSU{
    int n, comp, *parent, *rank;
    DSU(int x){
        n = x;
        comp = n;
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i = 1;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(x == parent[x])return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int x, int y){
        int xroot = find(x), yroot = find(y);
        if(xroot == yroot){
            return false;
        }
        if(rank[xroot] <= rank[yroot]){
            rank[yroot]+=rank[xroot];
            parent[xroot] = yroot;
        }
        else{
            rank[xroot]+=rank[yroot];
            parent[yroot] = xroot; 
        }
        return true;
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=1;
        for(auto x: edges){
            for(int y : x){
                n = max(n,y);
            }
        }
        DSU dsu(n);
        int red_conn_idx = 0;
        for(int index = 0;index<edges.size();index++){
            int u = edges[index][0];
            int v = edges[index][1];
            if(!dsu.merge(u,v)){
                red_conn_idx = index;
            }
        }
        return edges[red_conn_idx];
        
    }
};