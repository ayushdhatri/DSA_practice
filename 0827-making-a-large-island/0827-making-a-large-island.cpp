class Solution {
public:
    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    void dfs(int currRow, int currCol, int currColour, vector<vector<int>>& nodeColor, int &totalNodesColoured, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        visited[currRow][currCol] = true;
        totalNodesColoured += 1;
        
        // FIX 1: Use currRow and currCol instead of i and j
        nodeColor[currRow][currCol] = currColour; 
        
        for(int d = 0; d < 4; d++){
            int nrow = currRow + drow[d];
            int ncol = currCol + dcol[d];
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && visited[nrow][ncol] == false){
                dfs(nrow, ncol, currColour, nodeColor, totalNodesColoured, visited, grid);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        vector<int> color(n * m, 0); 
        vector<vector<int>> nodeColor(n, vector<int>(m, -1)); // Init with -1 to avoid confusion with color 0
        
        int initialColor = 0;
        int maxAns = 0; // Tracks our maximum island size

        // Phase 1: Paint all existing islands
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    int totalNodesColoured = 0;
                    
                    // FIX 2: Matched the parameter order to the DFS signature
                    dfs(i, j, initialColor, nodeColor, totalNodesColoured, visited, grid);
                    
                    color[initialColor] = totalNodesColoured;
                    maxAns = max(maxAns, totalNodesColoured); // Capture max size in case there are no 0s to flip
                    initialColor += 1;
                }
            }
        }
        
        // Phase 2: Evaluate every 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    
                    // Use unordered_set to automatically discard duplicate island colors
                    unordered_set<int> uniqueColors;
                    
                    for(int d = 0; d < 4; d++){
                        int adjRow = i + drow[d];
                        int adjCol = j + dcol[d];
                        if(adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m && grid[adjRow][adjCol] == 1){
                           uniqueColors.insert(nodeColor[adjRow][adjCol]);
                        }
                    }
                    
                    // Calculate theoretical size if we flip this 0
                    int currentPossibleSize = 1; // The flipped zero itself
                    for(int c : uniqueColors) {
                        currentPossibleSize += color[c];
                    }
                    
                    maxAns = max(maxAns, currentPossibleSize);
                }
            }
        }
        
        return maxAns;
    }
};