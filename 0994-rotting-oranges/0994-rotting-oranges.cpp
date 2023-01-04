class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>,int>>q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    
                 }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
      int time = 0;
        while(q.size()!=0)
        {
            
            
                pair<pair<int,int>, int>curr =q.front();
                q.pop();
                if(visited[curr.first.first][curr.first.second]==false&&grid[curr.first.first][curr.first.second]==2)
                {
                    visited[curr.first.first][curr.first.second]==true;
                    int prow = curr.first.first;
                    int pcol = curr.first.second;
                    int tm = curr.second;
                    time = max(time, tm);
                    for(int d = 0;d<4;d++)
                    {
                        int nrow = prow+drow[d];
                        int ncol = pcol+dcol[d];
                        if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&visited[nrow][ncol]==false&&grid[nrow][ncol]==1)
                        {
                            q.push({{nrow, ncol},tm+1});
                            grid[nrow][ncol]=2;
                        }
                    }
                    
                }
                
            
        }
      for(int i=0;i<m;i++)
      {
          for(int j =0;j<n;j++)
          {
              if(grid[i][j]==1)
                  return -1;
          }
          
      }
      return time;
        
        
        
        
    }
};