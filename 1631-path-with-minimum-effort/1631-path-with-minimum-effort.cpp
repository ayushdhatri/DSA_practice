class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // dist[i][j] = stores the minimuim effort to reach at i, j from (0, 0)
        int n = heights.size();
        int m = heights[0].size();
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0, +1, 0, -1};
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        >pq;
        dist[0][0] = 0;// because we are standing at first place and difference between anything will be heights[0][0]
        pq.push({dist[0][0], {0,0}});

        while(pq.size()!=0){
            int topNodeEffort = pq.top().first;
            int topNodeRow = pq.top().second.first;
            int topNodeCol = pq.top().second.second;
            pq.pop();
            if(topNodeRow == n-1 && topNodeCol == m-1)return topNodeEffort;
            if(dist[topNodeRow][topNodeCol] < topNodeEffort)continue;
            for(int d = 0;d<4;d++){
                int adjRow = topNodeRow + drow[d];
                int adjCol = topNodeCol + dcol[d];
                if(adjRow >= 0 && adjRow < n && adjCol >=0 && adjCol < m){
                    int adjNodeEffort = abs(heights[adjRow][adjCol] - heights[topNodeRow][topNodeCol]);
                    int overAllEffort = max(topNodeEffort, adjNodeEffort);
                    if(dist[adjRow][adjCol] > overAllEffort){
                        dist[adjRow][adjCol] = overAllEffort;
                        pq.push({overAllEffort, {adjRow, adjCol}});
                    }
                }
            }
        }
        return -1;


        
    }
};