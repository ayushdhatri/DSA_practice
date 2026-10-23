class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // we will start propogating signals from all source node K 
        // try to reach all the nodes in minimum time
        // if minimum time to reach is INF means the node is not reachabel hence we need to rutrun -1;
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i= 0;i<times.size();i++){
            int u, v, w;
            u = times[i][0];
            v = times[i][1];
            w = times[i][2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>
        >pq;
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(pq.size()!=0){
            int topNode = pq.top().second;
            int topNodeDist = pq.top().first;
            pq.pop();
            if(dist[topNode] > topNodeDist)continue;
            for(auto x: adj[topNode]){
                int adjNode = x.first;
                int adjNodeDist = x.second;
                if(dist[adjNode] > (topNodeDist + adjNodeDist)){
                    dist[adjNode] = topNodeDist + adjNodeDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};