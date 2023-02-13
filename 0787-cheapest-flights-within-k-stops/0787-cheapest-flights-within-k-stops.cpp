class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        int m = flights.size();
        for(int i=0;i<m;i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n, INT_MAX);
        dist[src]=0;
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        pq.push({0,{src,0}});
        while(pq.size()!=0)
        {
            int pstop = pq.top().first;
            int pnode = pq.top().second.first;
            int pdis = pq.top().second.second;
            pq.pop();
            for(auto x: adj[pnode])
            {
                int adjnode = x.first;
                int adjdis = x.second;
                if(pstop>k)continue;
                if(pdis+adjdis<dist[adjnode])
                {
                    dist[adjnode]=pdis+adjdis;
                    pq.push({pstop+1, {adjnode, dist[adjnode]}});
                }
            }
        } 
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
        
        
        
        
    }
};