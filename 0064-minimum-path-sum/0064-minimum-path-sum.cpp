class Solution {
public:
    int mps(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(row<0||col<0)
            return 1e5;
        if(row==0&&col==0)
        {
            return grid[0][0];
        }
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up = mps(row-1, col, grid, dp)+grid[row][col];
        int left = mps(row, col-1, grid, dp)+grid[row][col];
        return dp[row][col]=min(up, left);
        
      
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(); // rows
       int n = grid[0].size(); // cols
       vector<vector<int>>dp(m, vector<int>(n, -1)); 
       return mps(m-1, n-1,grid,dp); 
        
        
    }
};