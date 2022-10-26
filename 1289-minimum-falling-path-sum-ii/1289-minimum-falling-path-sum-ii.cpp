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
        
        vector<vector<int>>dp(n, vector<int>(n, 0));
//         for(int i=0;i<n;i++){
//             int temp = grid[0][i]+totalways(1,grid,i,dp);
//             ans = min(temp, ans);
//         }
//         return ans;
        for(int i=0;i<n;i++)
        {
            dp[0][i]=grid[0][i];
        }
       
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int ans = INT_MAX;
                    int temp;
                    for(int base=0;base<n;base++)
                    {
                        if(base==j)continue;
                        temp = grid[i][j]+dp[i-1][base];
                        ans=min(ans, temp);
                    }
                    dp[i][j]=ans;
                }
            }
        int fs= INT_MAX;
        for(int i=0;i<n;i++)
        {
            fs= min(fs, dp[n-1][i]);
        }
        return fs;
        
      
    }
};