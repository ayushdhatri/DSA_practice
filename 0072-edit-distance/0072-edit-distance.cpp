class Solution {
public:
int minOpeToconvert(int index1, int index2, string &word1, string &word2, vector<vector<int>>&dp){
    // pruing case
    if(index1 == word1.size()){
        // these many delete operation
        return word2.size()-index2;
    }
    if(index2 == word2.size()){
        return word1.size() - index1;
    }

    // base case
   


    // cache
     if(dp[index1][index2] != -1)return dp[index1][index2];    


    // transition
    int ans = INT_MAX;
    if(word1[index1] == word2[index2]){
        ans =  minOpeToconvert(index1 + 1, index2 + 1, word1, word2, dp);
    }
    else{
        // they are not same
        // Insert character
        ans = min(ans, 1 + minOpeToconvert(index1,index2 + 1, word1, word2, dp));


        // delete character
        ans = min(ans, 1 + minOpeToconvert(index1 + 1, index2,word1, word2, dp));


        // replace character
        ans = min(ans, 1 + minOpeToconvert(index1 + 1, index2 + 1, word1, word2, dp));
    }


    // save and return
    return dp[index1][index2] = ans;


}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return minOpeToconvert(0,0,word1, word2,dp);
        
    }
};