class Solution {
public:
int dp[2100];
int dp1[2100][2100];
int rec(int index, string &s){
    // pruning
    if(dp1[0][index])return 0;

    // base case
    if(index == 0)return 0;

    // cache
    if(dp[index] != -1)return dp[index];

    // transition
    int minCuts = INT_MAX;
    for(int start = index-1;start>=0;start--){
        // we can create one partition from start + 1 to index 
        if(dp1[start+1][index]){
            minCuts = min(minCuts, 1 + rec(start, s));
        }
    }


    // save and return
    return dp[index] = minCuts;
}

bool isPalindrome(int start, int end, string &s){
    // purning

    // base case
    if(start >= end)return true;

    // cache
    if(dp1[start][end] != -1)return dp1[start][end];

    // transition
    if(s[start] == s[end] && isPalindrome(start+1, end-1, s)){
        return dp1[start][end] = 1;
    }

    // save and return
    return dp1[start][end] = 0;
}

    int minCut(string s) {
        // here we will be using dp 2nd form
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp1));
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                isPalindrome(i,j,s);
            }
        }
        return rec(n-1, s);
       
    }
};