class Solution {
public:
    int moves(int row, int col, vector<vector<int>>&triangle, int dr, int dc, vector<vector<int>>&dp)
    {
        if(row==dr&&col<=dc)
            return triangle[row][col];
        if(dp[row][col]!=-1)
            return  dp[row][col];
        int down = triangle[row][col]+moves(row+1, col, triangle, dr, dc, dp);
        int dig = triangle[row][col]+moves(row+1, col+1, triangle, dr, dc, dp);
        return dp[row][col]=min(down, dig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row  = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>>dp(row,vector<int>(col, 0));
        for(int i=0;i<col;i++)dp[row-1][i]=triangle[row-1][i];
        for(int i=row-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                int down = triangle[i][j]+dp[i+1][j];
                int dig = triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down, dig);
            }
        }
        return dp[0][0];
        
        
        
        
        // return moves(0, 0, triangle, row-1, col-1, dp);
        
        
    }
};