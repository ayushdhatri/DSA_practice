class Solution {
public:
int dp[1010][1010];
bool rec(int startIndex, int endIndex, string &s){
    // pruning

    // base case
    if(startIndex >= endIndex){
        return true;
    }

    // cache
    if(dp[startIndex][endIndex] != -1)return dp[startIndex][endIndex];

    // transition
    bool isPalindrome = 0;
    if(s[startIndex] == s[endIndex]){
        isPalindrome = rec(startIndex+1, endIndex-1, s);
    }
   
    // save and return
    return dp[startIndex][endIndex] = isPalindrome;

}
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int startIndex = -1, endIndex = -1;
        int maxLen = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                bool isPalindrome = rec(i, j, s);
                int len = j-i+1;
                if(isPalindrome && len > maxLen){
                    maxLen = len;
                    startIndex = i;endIndex = j;
                }

            }
        }
        string ans = "";
        for(int index = startIndex;index<=endIndex;index++){
            ans+=s[index];
        }
        return ans;
    }
};