class Solution {
public:
int minASCII(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    // pruning case
    if(i == s1.size()){
        int ASCIISum = 0;
        for(int k = j;k<s2.size();k++){
            ASCIISum += int(s2[k]);
        }
        return ASCIISum;
    }
    if(j == s2.size()){
        int ASCIISum = 0;
        for(int k = i;k<s1.size();k++){
            ASCIISum += int(s1[k]);
        }
        return ASCIISum;

    }

    // base case



    // cache
    if(dp[i][j] != -1) return dp[i][j];

    // transition
    int ans = INT_MAX;
    if(s1[i] ==  s2[j]){
        ans = min(ans, (int)minASCII(i + 1, j + 1, s1, s2, dp));
    }
    else{
        ans = min(ans, int(s1[i]) + minASCII(i + 1, j, s1, s2, dp));
        ans = min(ans, int(s2[j]) + minASCII(i, j + 1, s1, s2, dp));
    
    }


    // save and return
    return dp[i][j] = ans;







}
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return minASCII(0,0,s1, s2, dp);

        
        
    }
};