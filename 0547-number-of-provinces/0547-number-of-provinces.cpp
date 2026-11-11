class Solution {
public:
struct DSU{
    int n, *par, *rank, comp;
    DSU(int totalNodes){
        this->n = totalNodes;
        this->par = new int[n];
        this->rank = new int[n];
        this->comp = totalNodes;
        for(int i = 0;i<n;i++){
            this->rank[i] = 1;
            this->par[i] = i;
        }
    }
    int find(int node){
        if(par[node] == node)return node;
        return par[node] = find(par[node]);
    }
    void merge(int nodeX, int nodeY){
        int rootX = find(nodeX);
        int rootY = find(nodeY);
        if(rootX == rootY)return;
        if(rank[rootX] >= rank[rootY]){
            rank[rootX] += rank[rootY];
            par[rootY] = rootX;
        }
        else{
            rank[rootY] += rank[rootX];
            par[rootX] = rootY;
        }
        comp--;
    }

};
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1){
                    // there is edge between u, and v
                    dsu.merge(i,j);
                }
            }
        }
        return dsu.comp;
    }
};