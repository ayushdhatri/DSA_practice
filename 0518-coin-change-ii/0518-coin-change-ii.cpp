class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1, 0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
            int value = coins[i];
            for(int target=1;target<=amount;target++)
            {
                if(target>=value)
                {
                    dp[target]+=dp[target-value];
                }
                
            }
        }
        
        return dp[amount];
    }
};