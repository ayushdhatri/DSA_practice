
#define ll long long
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
ll findMahhattanDist(int currNode, int nextNode, vector<vector<int>>&points){
    ll x1 = points[currNode][0], y1 = points[currNode][1];
    ll x2 = points[nextNode][0], y2 = points[nextNode][1];
    return abs(x1-x2) + abs(y1 - y2);
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        // here the only thing that is there is your negative point
        // how to deal with negative point
        // to calculate distnance it is easy because of abs;
        // how to take vertices
        // for positive vertices, we can take but how about negative vertices?
        // here lets give points[0] as node 0 and so on...
        vector<pair<int,pair<int, int>>>edgeWeight;
        for(int node = 0;node<points.size();node++){
            for(int nextNode = node+1;nextNode<points.size();nextNode++){
                if(node != nextNode){
                    ll manHattanDist = findMahhattanDist(node, nextNode, points);
                    edgeWeight.push_back({manHattanDist, {node, nextNode}});
                }
            }
        }
        // for(int i = 0;i<edgeWeight.size();i++){
        //     cout<<edgeWeight[i].first<<" "<<edgeWeight[i].second.first<<" "<<edgeWeight[i].second.second<<endl;
        // }
        sort(edgeWeight.begin(), edgeWeight.end());// Tc : )(2 * N ^ 2 log(N)) + inverseAuckMan(N) && SC : O(N^2)
        // start DSU
        int n = points.size();
        DSU dsu(n);
        ll minCost = 0;
        for(int i = 0;i<edgeWeight.size();i++){
            int currEdgeWeight = edgeWeight[i].first;
            int u = edgeWeight[i].second.first;
            int v = edgeWeight[i].second.second;
            int rootX = dsu.find(u);
            int rootY = dsu.find(v);
            if(rootX == rootY){
                // they already belong to same component so leave it
            }
            else{
                // add the edge in the graph and add the edgeWeight into your sum
                minCost += currEdgeWeight;
                dsu.merge(u, v);
            }


        }

        return (int)minCost;
        
        
    }
};