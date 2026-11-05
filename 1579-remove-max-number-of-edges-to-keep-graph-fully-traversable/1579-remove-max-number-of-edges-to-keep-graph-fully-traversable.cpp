class Solution {
public:
// make you dsu 1 based
struct DSU{
    int n, *par, *rank, comp;
    DSU(){}
    DSU(int totalNodes){
        this->n = totalNodes;
        this->par = new int[n+1];
        this->rank = new int[n+1];
        this->comp = n;
        for(int i = 1;i<=n;i++){
            this->rank[i] = 1;
        }
        for(int i = 1;i<=n;i++){
            this->par[i] = i;
        }
    }

    int findRoot(int node){
        if(par[node] == node)return node;
        return par[node] = findRoot(par[node]);// path compression
    }

    bool merge(int nodeX, int nodeY){
        int rootX = findRoot(nodeX);
        int rootY = findRoot(nodeY);
        if(rootX == rootY)return false;// same component;
        if(rank[rootX] <= rank[rootY]){
            par[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
        else{
            par[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        this->comp--;
        return true;
    }


};
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // one thing we can clearly observer here
        // type 3 node will always be advantage to us
        // so first create one component using type 3 node which wil ensure that initially which ever nodes can be connected comes
        // under the same compoent
        // next we need to think about two different edges 
        // one edge of type1 can be utilized by alice
        // another edge of typ2 can be utilized by bob only
        //
        int m = edges.size();
        // traverse and check which edges are of type 3
        DSU alice(n), bob(n);
        int edgeRequired = 0;
        for(int i = 0;i<m;i++){
            if(edges[i][0] == 3){
                bool aliceMerged = alice.merge(edges[i][1], edges[i][2]);
                bool bobMerged = bob.merge(edges[i][1], edges[i][2]);
                if(aliceMerged || bobMerged)edgeRequired+=1;
            }
        }
        // first traverse all the alice edges
        for(int i = 0;i<m;i++){
            if(edges[i][0] == 1){
                // it can traversed by alice only
                if(alice.merge(edges[i][1], edges[i][2]))edgeRequired+=1;
            }
        }
        for(int i = 0;i<m;i++){
            if(edges[i][0] == 2){
                // it can traversed by alice only
                if(bob.merge(edges[i][1], edges[i][2]))edgeRequired+=1;
            }
        }

        if(alice.comp == 1 && bob.comp == 1){
            return m - edgeRequired;
        }
        return -1;
        
    }
};