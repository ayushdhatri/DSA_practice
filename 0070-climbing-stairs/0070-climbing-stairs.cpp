class Solution {
public:
    // int totalways(int n,vector<int>&dp)
    // {
    //     if(n<0)
    //         return 0;
    //     if(n==0)
    //         return 1;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     int way1 = totalways(n-1,dp);
    //     int way2 = totalways(n-2,dp);
    //     return dp[n]= way1+way2;
    // }
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int way1 = dp[i-1];
            int way2 = 0;
            if(i-2>=0)
                way2 = dp[i-2];
            dp[i]= way1+way2;
        }
        return dp[n];
        
    }
};