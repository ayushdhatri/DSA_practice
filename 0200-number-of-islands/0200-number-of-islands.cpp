class Solution {
public:
    void bfs(int prow, int pcol, vector<vector<char>>&grid, vector<vector<bool>>&visited)
    {
        visited[prow][pcol]=true;
        queue<pair<int, int>>q;
        q.push({prow, pcol});
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(q.size()!=0)
        {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = crow+drow[i];
                int ncol = ccol+dcol[i];
                if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&visited[nrow][ncol]==false&&grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol]=true;
                    q.push({nrow, ncol});
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(visited[i][j]==false&&grid[i][j]=='1')
                {
                    bfs(i, j, grid, visited);
                    ans++;
                }
            }
        }
        
        
        
        
        
        return ans;
        
        
        
    }
};