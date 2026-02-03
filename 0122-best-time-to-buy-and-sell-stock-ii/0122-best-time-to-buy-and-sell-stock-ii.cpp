class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // Base case: dp[n][0] = dp[n][1] = 0 (already initialized)
        
        // Fill table backwards (from day n-1 to day 0)
        for (int level = n - 1; level >= 0; level--) {
            for (int holding = 0; holding <= 1; holding++) {
                if (holding) {
                    // Can sell or hold
                    int sell = prices[level] + dp[level + 1][0];
                    int hold = dp[level + 1][1];
                    dp[level][holding] = max(sell, hold);
                } else {
                    // Can buy or skip
                    int buy = -prices[level] + dp[level + 1][1];
                    int skip = dp[level + 1][0];
                    dp[level][holding] = max(buy, skip);
                }
            }
        }
        
        return dp[0][0];  // Start from day 0, not holding any stock
    }
};