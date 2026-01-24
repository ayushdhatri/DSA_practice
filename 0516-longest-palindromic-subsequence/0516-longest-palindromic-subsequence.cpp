class Solution {
public:
int lcs(int index1, int index2, string &s, string &t, vector<vector<int>>&dp){
    // pruining case


    // base case
    if(index1 >= s.size() || index2 >= t.size())return 0;
    // cache
    if(dp[index1][index2] != -1)return dp[index1][index2];

    // transition
    int ans = 0;
    if(s[index1] == t[index2]){
        ans = 1 + lcs(index1 +1, index2 + 1, s, t, dp);
    }
    else{
        ans = max(ans,lcs(index1 + 1,index2, s, t, dp));
        ans = max(ans, lcs(index1, index2 + 1, s, t, dp));
    }

    // save and return
    return dp[index1][index2] = ans;
}
    int longestPalindromeSubseq(string s) {
       string t = s;
       reverse(t.begin(), t.end());
       int n = s.size();
       vector<vector<int>>dp(n, vector<int>(n, -1));
       return lcs(0,0,s, t, dp);

        
    }
};