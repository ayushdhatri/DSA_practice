class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        int cheapFlightPrice = INT_MAX;
        vector<pair<int, int>>adj[n];
        int m = flights.size();
        for(int i= 0;i<m;i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        vector<int>price(n, 1e9);
        priority_queue<pair<int, pair< int, int>>, 
        vector<pair< int, pair< int, int>>>, 
        greater<pair< int, pair< int, int>>>
        >pq;
        price[src]=0;
        pq.push({0,{src, 0}});
        while(pq.size()!=0){
            int currStops = pq.top().first;
            int currNode = pq.top().second.first;
            int currPrice = pq.top().second.second;
            pq.pop();
            for(auto x: adj[currNode]){
                int adjNode = x.first;
                int adjPrice = x.second;
                if(currStops+1<=(k+1)){
                    if(currPrice+adjPrice<price[adjNode]){
                        price[adjNode]= currPrice + adjPrice;
                        pq.push({currStops+1,{adjNode, price[adjNode]}});
                    }
                }
            }
            
        }
        if(price[dst]==1e9)return -1;
        return price[dst];
        return -1;
    









        return cheapFlightPrice;
        
    }
};