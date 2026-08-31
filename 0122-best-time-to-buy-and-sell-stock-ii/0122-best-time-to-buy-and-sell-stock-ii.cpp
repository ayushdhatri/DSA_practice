class Solution {
public:
int dp[30010][2];
int rec(int level, bool hasStock, vector<int>&prices){
    // pruning

    // base case
    if(level >= prices.size())return 0;

    // Cache
    if(dp[level][hasStock] != -1)return dp[level][hasStock];

    // transition
    int result = 0;
    if(hasStock){
        // you already have one stock in your hand
        int sellHasStock = prices[level] + rec(level + 1, !hasStock, prices);//I sold my stock and move to next day
        int buyNewStockAfterSellingOldOne = rec(level + 1, hasStock, prices);// since I bought today 
        result = max(sellHasStock, buyNewStockAfterSellingOldOne);

    }
    else{
        // if you dont have stock then you buy today
        int buyStock = -prices[level] + rec(level + 1, true, prices);
        int dontDoAnything = rec(level + 1, hasStock, prices);
        result = max(buyStock, dontDoAnything);

    }
    // save and return
    return dp[level][hasStock] = result;
}
    int maxProfit(vector<int>& prices) {
        // this question is of form 1
        memset(dp, -1, sizeof(dp));
        return rec(0,false, prices);
        
    }
};