class Solution {
public:
int longPath(int currRow, int currCol, vector<vector<int>>&matrix, vector<vector<int>>&dp){
    // pruining

    // base case

    // cache
    if(dp[currRow][currCol] != -1){
        return dp[currRow][currCol];
    }


    // transition
    int drow[] = {-1,0,+1,0};
    int dcol[] = {0,+1,0,-1};
    int ans = 1;

    for(int index = 0;index < 4;index++){
        int nrow = currRow + drow[index];
        int ncol = currCol + dcol[index];
        if(nrow >=0 && nrow <matrix.size() && ncol >=0 && ncol < matrix[0].size() && (matrix[currRow][currCol] < matrix[nrow][ncol])){
            ans = max(ans, 1 + longPath(nrow,ncol, matrix, dp));
        }
    }


    // save and return
    return dp[currRow][currCol] = ans;




}
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        /*
        -> if we are at index i, j what I will do is find the neighebours whose value is less than i, j and attach to which means
        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j+1],dp[i+1][j], dp[i][j-1]);
        Now I am thinking from where to start(I need to try on all the index of matrix and caluclate it);

        */

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = INT_MIN;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans, longPath(i,j,matrix,dp));
            }
        }
        return ans;
    

    }
};