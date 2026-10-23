class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        
        // 1. Use long long for the edge weights
        vector<vector<pair<int, long long>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            long long time = roads[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        // 2. Priority queue must store <long long (time), int (node)>
        priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
        
        // 3. dist array must be long long and initialized to LLONG_MAX
        vector<long long> dist(n, LLONG_MAX);
        int src = 0, dest = n - 1;
        dist[src] = 0;
        pq.push({0, 0});
        
        vector<int> ways(n, 0);
        ways[src] = 1;
        
        while(pq.size() != 0){
            long long topNodeTime = pq.top().first; // 4. Use long long here
            int topNode = pq.top().second;
            pq.pop();
            
            if(dist[topNode] < topNodeTime) continue;
            
            for(auto x : adj[topNode]){
                int adjNode = x.first;
                long long adjNodeTime = x.second; // 5. Use long long here
                
                if(dist[adjNode] > (topNodeTime + adjNodeTime)){
                    dist[adjNode] = topNodeTime + adjNodeTime;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[topNode]; // Modulo already applied in else-if, not strictly needed here
                }
                else if(dist[adjNode] == (topNodeTime + adjNodeTime)){
                    ways[adjNode] = (ways[adjNode] + ways[topNode]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};