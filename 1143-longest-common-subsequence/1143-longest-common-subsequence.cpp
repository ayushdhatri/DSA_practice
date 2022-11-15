class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
       int n = s1.size();
       int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int index1=1;index1<=n;index1++)
        {
            for(int index2=1;index2<=m;index2++)
            {
                if(s1[index1-1]==s2[index2-1])
                {   
                    dp[index1][index2]=1 + dp[index1-1][index2-1];
                }
                else
                {
                    int a = dp[index1-1][index2];
                    int b = dp[index1][index2-1];
                    dp[index1][index2]=max(a, b);
                }
            }
        }
        return dp[n][m];
        
    }
};
