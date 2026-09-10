class Solution {
public:
int dp[510][510];
int rec(int startIndex, int endIndex, string &s){
    // pruning

    //base case
    if(startIndex >= endIndex){
        return 0;
    }

    // cache
    if(dp[startIndex][endIndex] != -1 )return dp[startIndex][endIndex];

    // transition
    int minWays = INT_MAX;
    int way1 = minWays, way2 = minWays, way3 = minWays;
    if(s[startIndex] == s[endIndex]){
        way1 = rec(startIndex +1, endIndex-1, s);
    }
    else{
        way2 = 1 + rec(startIndex, endIndex-1, s);
        way3 = 1 + rec(startIndex + 1, endIndex, s);
    }

    // save and return
    return dp[startIndex][endIndex] = min({way1, way2, way3});
}
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return rec(0, n-1, s);

    }
};