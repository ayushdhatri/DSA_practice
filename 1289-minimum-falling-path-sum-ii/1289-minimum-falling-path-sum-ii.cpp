class Solution {
public:
    int totalways(int row,vector<vector<int>>&grid, int lastindex, vector<vector<int>>&dp)
    {
        if(row==grid.size())
            return 0;
        if(dp[row][lastindex]!=-1)
            return dp[row][lastindex];
        int ans = INT_MAX;
        for(int i=0;i<grid.size();i++)
        {
            if(i==lastindex)continue;
            int temp = grid[row][i]+totalways(row+1,grid,i,dp);
            ans  = min(ans, temp);
        }
        return dp[row][lastindex]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            int temp = grid[0][i]+totalways(1,grid,i,dp);
            ans = min(temp, ans);
        }
        return ans;
      
    }
};