class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();// rows
        int n = matrix[0].size();// cols
        vector<vector<int>>dp(m, vector<int>(n));
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]=='0')
                dp[0][i]=0;
            else
                dp[0][i]=1;
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]=='0')
                dp[i][0]=0;
            else
                dp[i][0]=1;
        }
        for(int row=1;row<m;row++)
        {
            for(int col=1;col<n;col++)
            {
                if(matrix[row][col]!='0')
                    dp[row][col]=1+min({dp[row-1][col-1],dp[row-1][col],dp[row][col-1]});
                else
                    dp[row][col]=0;
            }
        }
        int maxarea=INT_MIN;
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxarea = max(maxarea, dp[i][j]);
            }
        }
       
        if(maxarea==INT_MAX)
            return 0;
        return maxarea*maxarea;
        
        
        
    }
};