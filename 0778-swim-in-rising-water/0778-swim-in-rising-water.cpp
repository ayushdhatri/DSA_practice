class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>time(n, vector<int>(m, INT_MAX));
        pq.push({grid[0][0],{0,0}});
        time[0][0]=grid[0][0];
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(pq.size()!=0)
        {
            int prow = pq.top().second.first;
            int pcol =pq.top().second.second;
            int ptime = pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = prow+drow[i];
                int ncol= pcol+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n)
                {
                    if(grid[nrow][ncol]>=ptime&&grid[nrow][ncol]<time[nrow][ncol])
                    {
                        time[nrow][ncol]=grid[nrow][ncol];
                        pq.push({grid[nrow][ncol], {nrow,ncol}});
                    }
                    else if(grid[nrow][ncol]<ptime&&ptime<time[nrow][ncol])
                    {
                        time[nrow][ncol]=ptime;
                        pq.push({ptime, {nrow, ncol}});
                        
                    }
                }
            }
        }
        return time[n-1][m-1];
         
    }
};