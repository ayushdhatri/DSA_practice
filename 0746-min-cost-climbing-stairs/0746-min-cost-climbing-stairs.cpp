class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    
        int n = cost.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int mincost = cost[i];
            int minways = INT_MAX;
            minways = min(minways, dp[i+1]);
            if(i+2<=n)
                minways  = min(minways, dp[i+2]);
            if(minways==INT_MAX)
                dp[i]=minways;
            else
                dp[i]=minways+mincost;
        }
        return min(dp[0],dp[1]);
        
        
    }
};