class Solution {
public:
int solve(int index, int holdState, vector<int>&prices, vector<vector<int>>&dp){
    // pruining 


    // base case
    if(index >= prices.size())return 0;

    // cache
    if(dp[index][holdState] != -1)return dp[index][holdState];


    // transition
    int result = 0;
    if(holdState == 0){
        int doNothing = solve(index + 1, holdState, prices, dp);
        int buy = solve(index + 1, !holdState, prices, dp) - prices[index];
        result = max(doNothing, buy);
    }
    else{
        int doNothing = solve(index + 1, holdState, prices, dp);
        int sell = solve(index + 2, !holdState, prices, dp) + prices[index];
        result = max(doNothing, sell);
    }
    dp[index][holdState] = result;
    // save and return
    return result;
}
    int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
        
    }
};