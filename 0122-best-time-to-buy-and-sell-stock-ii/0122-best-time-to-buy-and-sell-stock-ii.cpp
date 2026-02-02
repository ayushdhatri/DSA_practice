class Solution {
public:
    int max_profit(int index, int buy, vector<int>&prices,vector<vector<int>>&dp){
        if(index==prices.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        if(buy){
            profit = max(-prices[index]+max_profit(index+1, 0,prices,dp),max_profit(index+1, 1,prices,dp));
        }
        else{
            profit = max(prices[index]+max_profit(index+1, 1,prices,dp),max_profit(index+1, 0,prices,dp));

        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return max_profit(0,1,prices,dp);

        
    }
};