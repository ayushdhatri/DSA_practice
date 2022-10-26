class Solution {
public:
    int totalways(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&moveCost, vector<vector<int>>&dp)
    {
        if(row==grid.size()-1)
            return grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int ans = 1e5;
        for(int i=0;i<grid[0].size();i++)
        {
            int temp = grid[row][col]+moveCost[grid[row][col]][i]+totalways(row+1,i,grid, moveCost,dp);
            ans = min(temp, ans);
        }
        return dp[row][col]=ans;
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();// n represent rows
        int m = grid[0].size();// m represent column
        int ans = 1e5;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        for(int i=0;i<m;i++)
        {
          int temp = totalways(0, i, grid, moveCost,dp);
            ans = min(ans, temp);
        }
        return ans;
        
       
        
    }
};