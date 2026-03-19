const int INF = 1e9;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        deque<pair<int, pair<int, int>>>dq;
        dq.push_back({0,{0,0}});
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(dq.size()!=0){
            int currObstCount = dq.front().first;
            int currRow = dq.front().second.first;
            int currCol = dq.front().second.second;
            dq.pop_front();
            if(currRow == m-1 && currCol == n-1){
                return currObstCount;
            }
            for(int i = 0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow >= 0 && nrow < m && ncol>=0 && ncol<n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                   if(grid[nrow][ncol] == 1){
                        dq.push_back({currObstCount + 1, {nrow, ncol}});
                   }
                   else
                   {
                        dq.push_front({currObstCount, {nrow, ncol}});
                   }

                }
            }

             
        }
        return -1;
        
    }
};