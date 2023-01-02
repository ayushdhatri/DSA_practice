class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>>&visited, vector<vector<char>>&grid)
    {
        queue<pair<int, int>>q;
        q.push({row, col});
        while(q.size()!=0)
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                pair<int, int>curr = q.front();
                q.pop();
                if(visited[curr.first][curr.second]==false)
                {
                    visited[curr.first][curr.second]=true;
                    int prow=curr.first;
                    int pcol = curr.second;
                    if(pcol-1>=0&&grid[prow][pcol-1]=='1'&&visited[prow][pcol-1]==false)
                        q.push({prow, pcol-1});
                    if(pcol+1<grid[0].size()&&grid[prow][pcol+1]=='1'&&visited[prow][pcol+1]==false)
                        q.push({prow, pcol+1});
                    if(prow-1>=0&&grid[prow-1][pcol]=='1'&&visited[prow-1][pcol]==false)
                        q.push({prow-1, pcol});
                    if(prow+1<grid.size()&&grid[prow+1][pcol]=='1'&&visited[prow+1][pcol]==false)
                        q.push({prow+1, pcol});
                    
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                char ch = grid[i][j];
                if(ch=='1'&&visited[i][j]==false)
                {
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
       return count;
        
        
    }
};