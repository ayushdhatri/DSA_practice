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
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        // for(int i=0;i<n;i++)
        //     dp[0][i]=0;
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=1e5;
            
        }
        for(int index = 1;index<n;index++)
        {
            for(int sikka = 0;sikka<=amount;sikka++)
            {
                int pick = 1e5;
                if(sikka>=coins[index])
                    pick = 1 + dp[index][sikka-coins[index]];
              //  int notpick = 1e5;
                int notpick = dp[index-1][sikka];
                dp[index][sikka]=min(pick, notpick);
            }
        }
        if(dp[n-1][amount]>=1e5)
            return -1;
        return dp[n-1][amount];
    }
};