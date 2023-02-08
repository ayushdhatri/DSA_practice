class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=1e9;
        }
        for(int row=1;row<n;row++)
        {
            for(int target = 0;target<=amount;target++)
            {
                int notinclude = dp[row-1][target];
                int include = 1e9;
                if(target>=coins[row]) {
                    include = 1+dp[row][target-coins[row]];
                }
                dp[row][target]=min(notinclude,include);
            }
        }
        if(dp[n-1][amount]!=1e9)
        return dp[n-1][amount];
        return -1;
        
        
        
        
    }
};