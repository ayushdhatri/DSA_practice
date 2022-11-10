class Solution {
public:
    int mincoins(vector<int>&coins, int amount, int index, vector<vector<int>>&dp)
    {
        if(amount==0)
            return 0;
            
        if(index==0)
        {
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e5;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick = 1e5;
        if(amount>=coins[index])
          pick=1+ mincoins(coins,amount-coins[index], index,dp);
        int notpick = 0 + mincoins(coins, amount, index-1,dp);
        return dp[index][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1, -1));
        int temp = mincoins(coins, amount,n-1,dp);
        if(temp>=1e5)
            return -1;
        return temp;
        
    }
};