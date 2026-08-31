class Solution {
public:
int dp[100100][2][3];
int rec(int level, int hasStock, int maxTransaction, vector<int>&prices){
    // pruning
    if(maxTransaction == 0){
        return 0;
    }

    // base case
    if(level >= prices.size())return 0;

    // cache1
    if(dp[level][hasStock][maxTransaction] != -1)return dp[level][hasStock][maxTransaction];

    // transition
    int result = 0;
    if(hasStock){
        // you can sell this stock get some profit and complete a transaction
        int sellHasStock = prices[level] + rec(level + 1, !hasStock, maxTransaction - 1, prices);
        int dontSellTodayMoveNextDay = rec(level + 1, hasStock, maxTransaction, prices);
        result = max(sellHasStock,dontSellTodayMoveNextDay);
    }
    else{
        // I need to buy a new stock
        if(maxTransaction > 0){
            // then only we can decide to buy a new stock or start a new transaction
            int buyStockToday = -prices[level] + rec(level + 1, !hasStock, maxTransaction, prices);
            int dontBuyTodayMoveNextDay = rec(level + 1, hasStock, maxTransaction, prices);
            result = max(buyStockToday, dontBuyTodayMoveNextDay);
        }

    }


    // save and return 
    return dp[level][hasStock][maxTransaction] = result;
}
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return rec(0, false, 2, prices);
        
    }
};