class Solution {
public:
int dp[ 510][510];
int rec(int level1, int level2, string &word1, string &word2){
    // pruing

    // base case
    if(level1 >= word1.size() || level2 >= word2.size())return 0;

    // cache
    if(dp[level1][level2] != -1)return dp[level1][level2];

    // transition
    int ans = 0;
    if(word1[level1] == word2[level2]){
        ans = max(ans, 1 + rec(level1 + 1, level2 + 1, word1, word2));
    }
    else{
        ans = max({ans, rec(level1 + 1, level2, word1, word2), rec(level1, level2 + 1, word1, word2)});
    }

    // save and return
    return dp[level1][level2] = ans;
}
    int minDistance(string word1, string word2) {
       //  if word1, and word2 are same then no steps required return 0
       // the only step we can take is to delete the characters from either string 
       // sea and eat 
       // le etco de and etco
       // if we find the common characters in sequence and remove from both the string what remains in each of them is supposed 
       // to be deleted
       memset(dp, -1, sizeof(dp));
       int lcs = rec(0,0,word1,word2);
       return ((word1.size() - lcs) + (word2.size() - lcs));

    }
};