class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n+1,vector<int>(m+1,1e9));
        priority_queue<pair<int,pair<int, int>>,
        vector<pair<int,pair<int, int>>>,
        greater<pair<int,pair<int, int>>>
        >pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(pq.size()!=0){
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            int currEle = pq.top().first;
            pq.pop();

            for(int i = 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow >=0 && nrow<n && ncol >=0 && ncol<m){
                    if(max(grid[nrow][ncol],currEle) < dist[nrow][ncol]){
                        dist[nrow][ncol] = max(grid[nrow][ncol],currEle);
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];


        
    }
};