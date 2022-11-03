class Solution {
public:
    int mincoins(int index, vector<int>&coins, int amount, vector<vector<int>>&dp)
    {
        if(amount==0)
            return 0;
        if(index==0)
        {
            if(amount%coins[index]==0)
                return amount/coins[index];
            return 1e5;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick = 1e5;
        if(amount>=coins[index])
             pick = 1 + mincoins(index, coins, amount-coins[index],dp);
        int notpick = 0;
        notpick = mincoins(index-1, coins, amount,dp);
        return dp[index][amount] = min(pick, notpick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int temp =mincoins(n-1, coins, amount, dp);
        if(temp>=1e5)
            return -1;
        return temp;
    }
};