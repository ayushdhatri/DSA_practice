class Solution {
public:
struct DSU{
    int n, *par, *rank;
    DSU(){}
    DSU(int totalNodes){
        this->n = totalNodes;
        this->par = new int[n+1];
        this->rank = new int[n+1];
        for(int i = 0;i<=n;i++){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // if anything is tree there is n-1 edges.
        // initially it was tree so in a tree we know that there are total n-1 edges
        // now they addded one edge and we are not aware which edge was added.
        // but lets say we start with no edges initially 
        int lastEdgeIndex = -1;// intially we dont know 
        int m = edges.size();
        int n = m;
        DSU dsu(n);
        for(int i = 0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int rootU = dsu.find(u);
            int rootV = dsu.find(v);
            if(rootU == rootV)// belong to same component
            {
                lastEdgeIndex = i;
            }
            else{
                dsu.merge(u,v);
            }
        
        }
        return edges[lastEdgeIndex];



    }
};