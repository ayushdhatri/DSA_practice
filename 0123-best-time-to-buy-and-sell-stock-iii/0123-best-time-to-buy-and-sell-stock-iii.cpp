class Solution {
public:
int solve(int index, int holdState, int txnLeft,vector<int>&prices ,vector<vector<vector<int>>>&dp){
    // pruning case
    // base case
    if(index >= prices.size() || txnLeft == 0)return 0;

    // cache
    if(dp[index][holdState][txnLeft] != -1)return dp[index][holdState][txnLeft];
    // transition
    int result = 0;
    if(holdState == 0){
        int doNothing = solve(index + 1, holdState, txnLeft, prices, dp);
        int buy = solve(index + 1, !holdState, txnLeft,prices,dp) - prices[index];
        result = max(doNothing, buy);
    }
    else{
        int doNothing = solve(index + 1, holdState, txnLeft, prices, dp);
        int sell = solve(index + 1, !holdState, txnLeft - 1, prices, dp) + prices[index];
        result = max(doNothing, sell);
    }
    dp[index][holdState][txnLeft] = result;

    // save and return
    return  dp[index][holdState][txnLeft];




}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,2,prices,dp);


        
    }
};