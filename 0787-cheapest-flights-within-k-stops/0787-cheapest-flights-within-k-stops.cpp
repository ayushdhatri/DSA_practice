class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        k+=1;
        for(int i = 0;i<flights.size();i++){
            int from, to, price;
            from = flights[i][0];
            to = flights[i][1];
            price = flights[i][2];
            adj[from].push_back({to, price});
        }
        
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        >pq;
        vector<vector<int>>price(n, vector<int>(k+1, INT_MAX));
        price[src][0] = 0;
        pq.push({0,{src, 0}});

        while(pq.size() != 0){
            int topNodePrice = pq.top().first;
            int topNode = pq.top().second.first;
            int stopsSoFar = pq.top().second.second;
            pq.pop();
            if(topNode == dst){
                return topNodePrice;
            }
            if(price[topNode][stopsSoFar] < topNodePrice)continue;

            for(auto x: adj[topNode]){
                int adjNode = x.first;
                int adjNodePrice = x.second;
                if(stopsSoFar + 1 <= k && price[adjNode][stopsSoFar+1] > (topNodePrice + adjNodePrice)){
                    price[adjNode][stopsSoFar + 1] = topNodePrice + adjNodePrice;
                    pq.push({price[adjNode][stopsSoFar + 1], {adjNode, stopsSoFar + 1}});
                    
                }
            }
        }
        return -1;



    }
};