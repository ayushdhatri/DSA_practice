class Solution {
public:
    int totalways(int row, int col, vector<vector<int>>&matrix, vector<vector<int>>&dp)
    {
        if(row<0||col>=matrix.size()||col<0)
            return 1e5;
        if(row==0)
            return matrix[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int leftdig = matrix[row][col] + totalways(row-1, col-1, matrix,dp);
        int rightdig = matrix[row][col] + totalways(row-1, col+1, matrix,dp);
        int up = matrix[row][col] + totalways(row-1,col, matrix,dp);
        return dp[row][col] = min(leftdig, min(rightdig, up));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n;
        int ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                int down = matrix[i][j] + dp[i-1][j];
                int leftdig = 1e5;
                if(j-1>=0)
                    leftdig = matrix[i][j] + dp[i-1][j-1];
                int rightdig = 1e5;
                if(j+1<n)
                    rightdig = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(down, min(leftdig, rightdig));
            }
            
        }
        
            
              
        
        for(int i=0;i<n;i++)
        {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
        
        
        
    }
};