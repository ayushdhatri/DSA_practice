class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int  m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0||i==(m-1)||j==0||j==(n-1))
                {
                    if(grid[i][j]==1)
                    {
                        visited[i][j]=1;
                        q.push({i, j});
                    }
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(q.size()!=0)
        {
            int prow = q.front().first;
            int pcol = q.front().second;
            q.pop();
            // traversing in all four direction
            for(int d = 0;d<4;d++)
            {
                int nrow = prow+drow[d];
                int ncol = pcol+dcol[d];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&visited[nrow][ncol]==false&&grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol]=true;
                    q.push({nrow, ncol});
                }
            }
        }
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
              if(visited[i][j]==false&&grid[i][j]==1)
                  count++;
            }
        }
        return count;
        
        
    }
};