class Solution {
public:
struct DSU{
    int n, *par, *rank, comp;
    DSU(){}
    DSU(int totalNodes){
        this->n = totalNodes;
        this->par = new int[n];
        this->rank = new int[n];
        this->comp = n;
        for(int i = 0;i<n;i++){
            this->par[i] = i;
            this->rank[i] = 1;
        }
    }

    int findRoot(int node){
        if(par[node] == node)return node;
        return par[node] = findRoot(par[node]);
    }

    bool merge(int nodeX, int nodeY){
        int rootX = findRoot(nodeX);
        int rootY = findRoot(nodeY);
        if(rootX == rootY) return true;
        if(rank[rootX] >= rank[rootY]){
            rank[rootX] += rank[rootY];
            par[rootY] = rootX;
        }
        else{
            rank[rootY] += rank[rootX];
            par[rootX] = rootY;
        }
        comp--;
        return false;
    }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        DSU dsu(n);
        int extraEdge = 0;
        for(int i = 0;i<m;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            bool isBelongToSameComponent = dsu.merge(u, v);
            if(isBelongToSameComponent){
                extraEdge+=1;
            }
        }
        int totalCompAfterRemovingExtraEdge = dsu.comp;
        // cout<<totalCompAfterRemovingExtraEdge<<" "<<extraEdge<<endl;
        if(extraEdge >= (totalCompAfterRemovingExtraEdge - 1)){
            return totalCompAfterRemovingExtraEdge - 1;
        }
        
        return -1;

        

    }
};