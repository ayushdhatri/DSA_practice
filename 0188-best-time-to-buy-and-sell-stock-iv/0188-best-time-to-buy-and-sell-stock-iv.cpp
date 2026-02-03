class Solution {
public:
int solve(int index, int holdState, int k,vector<int>&prices ,vector<vector<vector<int>>>&dp){
    // pruning case

    // base case
    if(index >= prices.size() || k == 0)return 0;

    // cache
    if(dp[index][holdState][k] != -1)return dp[index][holdState][k];

    // transition
    int result = 0;
    if(holdState == 0){
        int doNothing = solve(index + 1, holdState, k, prices, dp);
        int buy = solve(index + 1, !holdState, k, prices, dp) - prices[index];
        result = max(doNothing, buy);
    }
    else{
        int doNothing = solve(index + 1, holdState, k, prices, dp);
        int sell = solve(index + 1, !holdState, k-1, prices, dp) + prices[index];
        result = max(doNothing, sell);
    }
    dp[index][holdState][k] = result;
    // save and return
    return dp[index][holdState][k] = result;
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,0,k,prices,dp);
        
    }
};