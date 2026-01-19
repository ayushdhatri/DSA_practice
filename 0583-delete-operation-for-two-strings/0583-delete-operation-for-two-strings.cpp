class Solution {
public:
int minDelString(int index1, int index2, string &word1, string &word2, vector<vector<int>>&dp){
    // pruning case
    if(index1 == word1.size()){
        return word2.size() - index2;
    }
    if(index2 == word2.size()){
        return word1.size() - index1;
    }

    // base case


    // cache
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    // transition
    int ans = INT_MAX;
    if(word1[index1] == word2[index2]){
        ans = min(ans, minDelString(index1 + 1, index2 + 1, word1, word2, dp));
    }
    else{
        // if i delete charcter in frist string
        ans = min(ans, 1 + minDelString(index1 + 1, index2, word1, word2, dp));
        ans = min(ans, 1 + minDelString(index1, index2 + 1, word1, word2, dp));

    }


    // save and return
    return dp[index1][index2] = ans;

}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return minDelString(0,0,word1, word2,dp);

        
    }
};