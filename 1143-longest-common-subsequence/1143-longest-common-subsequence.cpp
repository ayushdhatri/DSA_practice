class Solution {
public:
int lcs(int index1, int index2, string &text1, string &text2, vector<vector<int>>&dp){
    // pruning

    // base case
    if(index1 >= text1.size() || index2>= text2.size())return 0;

    // cache
    if(dp[index1][index2] != -1)return dp[index1][index2];

    // transition
    int ans = 0;
    if(text1[index1] == text2[index2]){
        ans = 1 + lcs(index1 + 1, index2 + 1, text1, text2, dp);
    }
    else{
        ans = max(lcs(index1 + 1, index2, text1, text2, dp),
        lcs(index1, index2 + 1, text1, text2, dp));
    }

    // save and return
    return dp[index1][index2] = ans;

}
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return lcs(0,0,text1,text2,dp);
        
    }
};