class Solution {
public:
    int dp1[1001][1001];  // for palindrome check
    int dp2[1001][1001];  // for LPS length
    int bestStart = 0, bestLen = 1;
    bool palindromSubstr(int i, int j, string &s){
        if(i >= j) return true;
        if(dp1[i][j] != -1) return dp1[i][j];
        
        bool ans = false;
        if(s[i] == s[j]){
            ans = palindromSubstr(i+1, j-1, s);
        }
        return dp1[i][j] = ans;
    }
    
    int lps(int l, int r, string &s){
        // base case
        if(l == r) return 1;
        if(l > r) return 0;
        
        // cache - ADDED THIS!
        if(dp2[l][r] != -1) return dp2[l][r];
        
        // Check if entire substring is palindrome
        if(palindromSubstr(l, r, s)){
             int len = r - l + 1;
            if(len > bestLen){  // Update best palindrome
                bestLen = len;
                bestStart = l;
            }
            return dp2[l][r] = len;

        }
        
        // Try removing from left or right
        int ans = max(lps(l+1, r, s), lps(l, r-1, s));
        
        return dp2[l][r] = ans;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        lps(0, n-1, s);
        int ians = 0,jans = 0;
        int ans = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dp2[i][j] > ans){
                    ans = dp2[i][j];
                    ians = i;
                    jans = j;
                }
            }
        }
        return s.substr(bestStart,bestLen);
    }
};