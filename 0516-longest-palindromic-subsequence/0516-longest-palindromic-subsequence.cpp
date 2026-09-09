class Solution {
public:
int dp[1010][1010];
int rec(int l, int r, string &s){
    // pruning
    if(l > r)return 0;

    // base case
    if(l == r){
        return 1;
    }

    // cache
    if(dp[l][r] != -1)return dp[l][r];

    // transition
    int ans = 1;
    if(s[l] == s[r]){
        ans = 2 + rec(l + 1, r-1, s);
    }
    else{
        ans = max(rec(l+1, r, s), rec(l, r-1, s));
    }

    // save and return
    return dp[l][r] = ans;
}
    int longestPalindromeSubseq(string s) {
        memset(dp, -1,sizeof(dp));
        int n = s.size();
        return rec(0, n-1,s);
        
        
    }
};