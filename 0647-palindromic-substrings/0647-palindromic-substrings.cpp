class Solution {
public:
    int dp[1001][1001];
    
    bool palindromSubstr(int i, int j, string &s){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        if(s[i] == s[j]){
            ans = palindromSubstr(i+1, j-1, s);
        }
        return dp[i][j] = ans;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        
        int count = 0;
        
        // Check all possible substrings
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(palindromSubstr(i, j, s)){
                    count++;
                }
            }
        }
        
        return count;
    }
};