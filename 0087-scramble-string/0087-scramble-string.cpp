class Solution {
public:
int dp[31][31][31];
bool rec(int i, int j, int len, string &s1, string &s2){
    // pruning

    // base case
    if(len == 1){
        return s1[i] == s2[j];
    }

    // cache
    if(dp[i][j][len] != -1)return dp[i][j][len];
    // before making transition lets check if two string are anagram or not
    // if they are anagram then only we should check it
    bool is_anagram = false;
    int endIndex = i + len-1;
    unordered_map<char,int>freq;
    for(int k = 0;k<len;k++){
        freq[s1[i+k]]++;
        freq[s2[j+k]]--;
    }
    for(auto x: freq){
        if(x.second != 0){
            return dp[i][j][len] = false;
        }
    }
    // after this point we know the strings are anagram so we can divide them 
    // according to rules they defined

    // transition
    for(int currLen = 1;currLen<len;currLen++){
        int remLen = len - currLen;
        int remLenStartOnS1 = i + currLen;
        int remLenStartOns2 = j + currLen;
        // we form two substrings
        // one of len currLen and other of length remLen
        // here two cases are there 
        // we can swap 
        // if(rec(remLenStartOnS1, j,remLen, s1, s2) && rec(i,remLenStartOns2, currLen, s1, s2)){
        //     return dp[i][j][len] = true;
        // }
        if(rec(remLenStartOnS1, j, remLen, s1, s2) && rec(i, j + remLen, currLen, s1, s2)){
            return dp[i][j][len] = true;
        }

        // we cannot swap
        if(rec(i,j,currLen, s1, s2) && rec(remLenStartOnS1, remLenStartOns2, remLen, s1, s2)){
            return dp[i][j][len] = true;
        }
  

    }

    // save and return
    return dp[i][j][len] = false;
}
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        memset(dp, -1, sizeof(dp));
        return rec(0,0,n,s1,s2);

    }
};