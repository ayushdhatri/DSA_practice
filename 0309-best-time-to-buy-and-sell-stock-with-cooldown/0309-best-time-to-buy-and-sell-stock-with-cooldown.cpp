class Solution {
public:
int dp[5010][2];
int rec(int level, bool hasStock, vector<int>&prices){
    // pruning
    

    // base case
    if(level >= prices.size())return 0;

    // cache
    if(dp[level][hasStock] != -1)return dp[level][hasStock];

    // transition
    int result = 0;
    if(hasStock){
        // I alread have a stock
        // you need to sell it
        int sellHasStock = prices[level] + rec(level + 2, !hasStock, prices);
        int dontSellAndMoveToNextDay = rec(level + 1, hasStock, prices);
        result = max(sellHasStock,dontSellAndMoveToNextDay);
    }    
    else{
        // I dont have a stock 
        // I can either decide to buy it or simply skip this day and make choices for next day
        int buyStockToday = -prices[level] + rec(level + 1, !hasStock, prices);
        int dontBuyStockToday = rec(level + 1, hasStock, prices);
        result = max(buyStockToday,dontBuyStockToday);

    }

    // save and return
    return dp[level][hasStock] = result;
}
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return rec(0, false, prices);
        
    }
};