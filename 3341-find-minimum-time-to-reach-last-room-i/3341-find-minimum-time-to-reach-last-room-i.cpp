#define ll long long
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<ll>>dist(n+1, vector<ll>(m+1, 1e18));
        dist[0][0] = 0;
        priority_queue<pair<ll, pair<ll, ll>>,
        vector<pair<ll, pair<ll, ll>>>,
        greater<pair<ll, pair<ll, ll>>>
        >pq;
        pq.push({0,{0,0}});
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(pq.size()!=0){
            ll currTime = pq.top().first;
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            
            pq.pop();
            for(int i = 0;i<4;i++){
                int nrow = drow[i] + currRow;
                int ncol = dcol[i] + currCol;
                if(nrow >=0 && nrow < n && ncol>=0 && ncol < m){
                    ll adjTime = moveTime[nrow][ncol];
                    if(max(currTime, adjTime) + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = max(currTime, adjTime)+1;
                        pq.push({max(currTime, adjTime)+1,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];

        
    }
};