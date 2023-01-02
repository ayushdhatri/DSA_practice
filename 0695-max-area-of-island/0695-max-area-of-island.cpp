class Solution {
public:
    int bfs(int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&grid)
    {
        queue<pair<int, int>>q;
        q.push({row, col});
        int maxans =0;
        while(q.size()!=0)
        {
            int len = q.size();
            
            for(int i=0;i<len;i++)
            {
                pair<int, int>curr = q.front();
                q.pop();
                if(visited[curr.first][curr.second]==false)
                {
                    maxans++;
                    visited[curr.first][curr.second]=true;
                    int prow = curr.first;
                    int pcol = curr.second;
                    if(pcol-1>=0&&visited[prow][pcol-1]==false&&grid[prow][pcol-1]==1)
                        q.push({prow, pcol-1});
                    if(pcol+1<grid[0].size()&&visited[prow][pcol+1]==false&&grid[prow][pcol+1]==1)
                        q.push({prow,pcol+1});
                    if(prow-1>=0&&visited[prow-1][pcol]==false&&grid[prow-1][pcol]==1)
                        q.push({prow-1, pcol});
                    if(prow+1<grid.size()&&visited[prow+1][pcol]==false&&grid[prow+1][pcol]==1)
                        q.push({prow+1, pcol});
                }
            }
        }
        
        return maxans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(visited[i][j]==false&&grid[i][j]==1)
                {
                    int temp = bfs(i, j, visited, grid);
                    ans = max(ans, temp);
                }
             }
        }
        return ans;
    }
};