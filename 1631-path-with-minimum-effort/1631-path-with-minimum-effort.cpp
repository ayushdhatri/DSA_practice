class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        pq.push({0,{0,0}});
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(pq.size()!=0)
        {
            int pdis = pq.top().first;
            int prow = pq.top().second.first;
            int pcol = pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = prow+dr[i];
                int ncol = pcol+dc[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m)
                {
                    int neweffort = max(abs(heights[nrow][ncol]-heights[prow][pcol]),dist[prow][pcol]);
                    if(neweffort<dist[nrow][ncol])
                    {
                        dist[nrow][ncol]= neweffort;
                        pq.push({neweffort,{nrow ,ncol}});
                    }
                    
                }
                
            }
            
            
        }
        return dist[n-1][m-1];
            
        
    }
};