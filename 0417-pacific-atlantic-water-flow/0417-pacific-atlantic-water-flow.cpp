class Solution {
public:
    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        
        if (n == 0 || m == 0) return ans;

        // Use two separate visited arrays instead of a counter
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // Push border nodes into their respective queues and mark them visited
        for (int i = 0; i < n; i++) {
            pacificQueue.push({i, 0});
            pacific[i][0] = true;
            
            atlanticQueue.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            pacificQueue.push({0, j});
            pacific[0][j] = true;
            
            atlanticQueue.push({n - 1, j});
            atlantic[n - 1][j] = true;
        }

        // 1. BFS for Pacific Ocean
        while (!pacificQueue.empty()) {
            int r = pacificQueue.front().first;
            int c = pacificQueue.front().second;
            pacificQueue.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + drow[d];
                int nc = c + dcol[d];
                
                // Flow "uphill" to find cells that can reach the ocean
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                    !pacific[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    pacificQueue.push({nr, nc});
                    pacific[nr][nc] = true;
                }
            }
        }

        // 2. BFS for Atlantic Ocean
        while (!atlanticQueue.empty()) {
            int r = atlanticQueue.front().first;
            int c = atlanticQueue.front().second;
            atlanticQueue.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + drow[d];
                int nc = c + dcol[d];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                    !atlantic[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    atlanticQueue.push({nr, nc});
                    atlantic[nr][nc] = true;
                }
            }
        }

        // 3. Find intersection: cells that can reach BOTH oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};