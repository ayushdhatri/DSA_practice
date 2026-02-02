class Solution {
public:
    vector<vector<int>> dp;
    int n;
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(0, 0, prices);  // Start from day 0
    }
    
private:
    // dp(level, holding) = max profit from day 'level' to end
    int solve(int level, int holding, vector<int>& prices) {
        // Base case: past last day
        if (level >= n) {
            return 0;
        }
        
        // Cache check
        if (dp[level][holding] != -1) {
            return dp[level][holding];
        }
        
        // Transition - try all possible actions today
        int ans;
        
        if (holding) {
            // Can sell or hold
            int sell = prices[level] + solve(level + 1, 0, prices);
            int hold = solve(level + 1, 1, prices);
            ans = max(sell, hold);
        } else {
            // Can buy or skip
            int buy = -prices[level] + solve(level + 1, 1, prices);
            int skip = solve(level + 1, 0, prices);
            ans = max(buy, skip);
        }
        
        return dp[level][holding] = ans;
    }
};