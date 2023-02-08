class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int,pair<int, int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(pq.size()!=0)
        {
            int prow = pq.top().second.first;
            int pcol = pq.top().second.second;
            int pdis = pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = prow+drow[i];
                int ncol = pcol+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m)
                {
                    int neweffort = max(pdis, abs(heights[nrow][ncol]-heights[prow][pcol]));
                    if(neweffort<dist[nrow][ncol])
                    {
                        dist[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow, ncol}});
                    }
                }

            }
        }
        return dist[n-1][m-1];
        
        
    }
};