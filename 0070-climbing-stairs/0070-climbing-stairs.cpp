class Solution {
public:
    int totalways(int n,vector<int>&dp)
    {
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int way1 = totalways(n-1,dp);
        int way2 = totalways(n-2,dp);
        return dp[n]= way1+way2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return totalways(n,dp);
        
        
    }
};