class Solution {
public:
    int totalways(vector<int>&coins, int amount,int index, vector<vector<int>>&dp)
    {
        if(amount==0)
            return 1;
        if(index==0)
        {
            if(amount%coins[index]==0)
                return 1;
            return 0;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick =0;
        if(amount>=coins[index])
            pick = totalways(coins, amount-coins[index], index,dp);
        int notpick = totalways(coins, amount, index-1,dp);
        return dp[index][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return totalways(coins, amount, n-1, dp);
    }
};