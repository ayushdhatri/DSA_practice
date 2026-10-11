class Solution {
public:
const int INF = INT_MAX;
int drow[8] = {-1,-1,0,+1,+1,+1,0,-1};
int dcol[8] = {0,+1,+1,+1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // singel source shortest path
        if(grid[0][0] == 1)return -1;
        vector<vector<int>>dist(n, vector<int>(m, INF));
        queue<pair<int, int>>q;
        q.push({0,0});
        dist[0][0] = 1;

        while(q.size() != 0){
            int nodeRow = q.front().first;
            int nodeCol = q.front().second;
            int nodeDist = dist[nodeRow][nodeCol];
            q.pop();
            for(int d = 0;d<8;d++){
                int nrow = nodeRow + drow[d];
                int ncol = nodeCol + dcol[d];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && 
                    dist[nrow][ncol] > (nodeDist + 1)){
                        q.push({nrow, ncol});
                        dist[nrow][ncol] = nodeDist + 1;
                }
            }

        }

        if(dist[n-1][m-1] == INF){
            return -1;
        }
        return dist[n-1][m-1];
        
    }
};