class Solution {
public:
int dp[1010][1010];
int rec(int i, int j, string &s, string &t){
    // pruning
    // base case
    if(i >= s.size() || j >= t.size()){
        if(j >= t.size())return 1;
        return 0;
    }                                                           

    //cache
    if(dp[i][j] != -1)return dp[i][j];
    //transition
    int ans = 0;
    if(s[i] == t[j]){
        ans = ans + rec(i + 1, j+1, s, t);
    }
    ans = ans + rec(i+1, j, s, t);
   
    // save and return
    return dp[i][j] = ans;
}
    int numDistinct(string s, string t) {
        // lets say we find the count of lcs of string s and t // it is gurantted that lcs will be of exact length t.size()
        // we find the count of all lcs and amonng them few or all of them will be distinct
        // we need to count distinct once
        // here since the string are same
        // so what is different among them is the index 
        // s = "b a b g b a g", t = "bag"
        //      0 1 2 3 4 5 6
        // {0, 1, 3}, {0, 1, 6} , {0, 5, 6}, {2, 5, 6}, {4, 5, 6}
        // when finding lcs if I build this string then in that case I can keep them inside set and return the size
        // TC : N^2LogN
        // SC : 
        // s = "r a b b b i t"
        memset(dp, -1, sizeof(dp));
        return rec(0,0, s, t);


    }
};