class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n+1, vector<int>(m+1, 1e9));
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        >pq;
        dist[0][0] = 0;// no effort required to reach this state
        pq.push({0,{0,0}});
        int drow[]= {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(pq.size()!=0){
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            int currMinEffort = pq.top().first;
            // if (currRow == n-1 && currCol == m-1)
            //     return currMinEffort;

            pq.pop();
            for(int i = 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow >=0 && nrow < n && ncol>=0 && ncol<m){
                    int consDiff = abs(heights[nrow][ncol]-heights[currRow][currCol]);
                    
                    if(max(currMinEffort,consDiff) < dist[nrow][ncol]){
                        dist[nrow][ncol] = max(currMinEffort,consDiff);
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }

                }
            }

        }
        return dist[n-1][m-1];

        
    }
};