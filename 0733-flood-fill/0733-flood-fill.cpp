class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int ic = image[sr][sc];
        queue<pair<int, int>>q;
        q.push({sr, sc});
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        visited[sr][sc]=true;
        image[sr][sc]=color;
        while(q.size()!=0)
        {
            int prow = q.front().first;
            int pcol = q.front().second;
            q.pop();
            for(int d=0;d<4;d++)
            {
                int nrow = prow+drow[d];
                int ncol = pcol+dcol[d];
                if(nrow>=0&&nrow<image.size()&&ncol>=0&&ncol<image[0].size()&&visited[nrow][ncol]==false&&image[nrow][ncol]==ic)
                {
                    visited[nrow][ncol]=true;
                    image[nrow][ncol]=color;
                    q.push({nrow, ncol});
                    
                }
            }
            
            
        }
        return image;
        
        
    }
};