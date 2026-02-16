class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int >>adj[n+1];
        int m = times.size();
        //created adj list
        for(int i = 0;i<m;i++){
            int u = times[i][0];
            int v = times[i][1];
            int signalTime = times[i][2];
            adj[u].push_back({v, signalTime});
        }
        //Declare a priority queue
        priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        // push the node k into our pq
        pq.push({0,k});
        // declare the singalTime array 
        vector<int>signalTime(n+1, 1e9);
        signalTime[k]=0;

        while(pq.size()!=0){
            int tm = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x:adj[node]){
                 int adjNode = x.first;
                int adjNodeTime = x.second;
               if(tm+adjNodeTime<signalTime[adjNode]){
                    signalTime[adjNode]=tm + adjNodeTime;
                    pq.push({signalTime[adjNode],adjNode});
                }

            }
        }
        int ans =0;;

        for(int i = 1;i<=n;i++){
            if(signalTime[i]==1e9)return -1;
            ans = max(ans, signalTime[i]);
        }
        
        return ans;


        
    }
};