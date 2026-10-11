class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // will start multisource bfs push all the 1 to matrix
        // do bfs and update the distance for all zero
        // traverse matrix and take max of all grid whose value if 0;
        int n = grid.size();
        int m = n;
        vector<vector<int>>dist(n, vector<int>(n, -1));
        queue<pair<pair<int, int>,int>>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    dist[i][j] = 0;
                }
            }
        }
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(q.size()!=0){
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int currDist = q.front().second;
            q.pop();
            for(int i  = 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol <n && dist[nrow][ncol] == -1){
                    dist[nrow][ncol] = currDist + 1;
                    q.push({{nrow, ncol}, currDist+1});
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 0){
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        if(ans == 0)return -1;
        return ans;


        
    }
};