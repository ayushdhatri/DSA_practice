class Solution {
public:
    void bfs(int row, int col, int color, int ic, vector<vector<int>>&img, vector<vector<bool>>&visited)
    {
        queue<pair<int, int>>q;
        q.push({row, col});
        while(q.size()!=0)
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                pair<int, int>curr  = q.front();
                q.pop();
                if(visited[curr.first][curr.second]==false&&img[curr.first][curr.second]==ic)
                {
                    visited[curr.first][curr.second]=true;
                    int prow = curr.first;
                    int pcol = curr.second;
                    img[prow][pcol]=color;
                    if(pcol-1>=0&&visited[prow][pcol-1]==false&&img[prow][pcol-1]==ic)
                        q.push({prow, pcol-1});
                    if(pcol+1<img[0].size()&&visited[prow][pcol+1]==false&&img[prow][pcol+1]==ic)
                        q.push({prow, pcol+1});
                    if(prow-1>=0&&visited[prow-1][pcol]==false&&img[prow-1][pcol]==ic)
                        q.push({prow-1, pcol});
                    if(prow+1<img.size()&&visited[prow+1][pcol]==false&&img[prow+1][pcol]==ic)
                        q.push({prow+1, pcol});
                 }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        int n = image.size();
        int m = image[0].size();    
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        bfs(sr, sc, color, ic, image, visited);
        return image;
        
    }
};