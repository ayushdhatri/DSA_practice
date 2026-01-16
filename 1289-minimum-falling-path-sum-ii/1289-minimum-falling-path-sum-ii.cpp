class Solution {
public:
int minPathSum(int currRow, int currCol, vector<vector<int>>&grid, vector<vector<int>>&dp){
    // pruning
    if(currRow < 0 || currRow >=grid.size() || currCol < 0 || currCol >=grid[0].size()){
        return INT_MAX;
    }

    // base case
    if(currRow == grid.size()-1){
        return grid[currRow][currCol];
    }

    // cache
    if(dp[currRow][currCol] != 1e9){
        return dp[currRow][currCol];
    }

    // transition
    int ans = 1e9;
    for(int i = 0;i<grid[0].size();i++){
        if(currCol != i){
            ans = min(ans, grid[currRow][currCol] + minPathSum(currRow + 1, i, grid, dp));
        }
    }

    // save and return
    return dp[currRow][currCol] = ans;

}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(n,1e9));
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            ans = min(ans, minPathSum(0,i,grid, dp));
        }
        return ans;



        
    }
};