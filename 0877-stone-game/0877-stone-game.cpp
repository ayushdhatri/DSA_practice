class Solution {
public:
int dp[510][510];
int rec(int startIndex, int endIndex, vector<int>&piles){
    // pruning

    // base case
    if(startIndex >= endIndex){
        return 0;
    }

    // cache
    if(dp[startIndex][endIndex] != -1)return dp[startIndex][endIndex];

    // transition
    int maxScore = 0;
    maxScore = max(maxScore, piles[startIndex] - rec(startIndex+1, endIndex, piles));
    maxScore = max(maxScore, piles[endIndex] - rec(startIndex, endIndex - 1, piles));

    // save and return
    return dp[startIndex][endIndex] = maxScore;
}
    bool stoneGame(vector<int>& piles) {
        // lets defined an L = 0, r = n-1 dp(L, R) = maxScoreAlice can take
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        rec(0, n-1, piles);
        if(dp[0][n-1] >= 0)return true;
        return false;
        
    }
};