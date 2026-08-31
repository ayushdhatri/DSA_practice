class Solution {
public:
int dp[50010][2];
int rec(int level, int hasStock, int fee, vector<int>&prices){
    // pruning

    // baase case
    if(level >= prices.size())return 0;


    // cache
    if(dp[level][hasStock] != -1)return dp[level][hasStock];
    // transition
    int result = 0;
    if(hasStock){
        // you already own a stock
        int sellHasStock = prices[level] - fee + rec(level + 1, !hasStock, fee, prices);
        int moveToNextDayWithoutSelling = rec(level + 1, hasStock, fee, prices);
        result = max(sellHasStock, moveToNextDayWithoutSelling);

    }
    else{
        int buyStockToday = -prices[level] + rec(level + 1, !hasStock, fee, prices);
        int dontBuyStockMoveNextDay = rec(level + 1, hasStock, fee, prices);
        result = max(buyStockToday,dontBuyStockMoveNextDay);

    }


    // save and return
    return dp[level][hasStock] = result;

}
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return rec(0, false, fee, prices);

        
    }
};