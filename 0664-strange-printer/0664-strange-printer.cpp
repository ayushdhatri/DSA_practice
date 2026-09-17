class Solution {
public:
int dp[110][110];
int rec(int l, int r, string &s){
    // pruning
    if(l > r)return 0;

    // base case
    if(l == r)return 1;

    // cache
    if(dp[l][r] != -1)return dp[l][r];

    // transition
    int minScore = INT_MAX;// got repainting by itself
    int way1 = 1 + rec(l, r-1, s);
    for(int index = r-1;index>=l;index--){
        if(s[index] == s[r]){
            // I can extend that stroke
            minScore = min(minScore, rec(l,index, s) + rec(index+1, r-1, s));
        }
    }
    minScore = min(minScore, way1);


    // save and return
    return dp[l][r] = minScore;
}
    int strangePrinter(string s) {
        // first of all constraints are less
        // a a a b b b 
        // here all similar elements were grouped together(mean sorted)
        // so simply like answer will be count of distnct characters that many operations
        // that printed need to do and in each operation it need to print the count
        // but here we are not worried about the count , instead we are counting operations.
        // lets look at one more example
        // so basically we are having nothing in our hand like empty string and with 
        // the help of printer we are going to print it
        // target = a b a (3 lenght sequence )
        // according to mee we should we should try printing the most frequent character
        // lets say for a b a -> a is apearing more frequent
        // print a 3 times a a a -> now you saw that at 1st index character is different
        // so print b
        // so print the sequence with most most frequent character and then replace
        // the different character at index(so different)
        // but one catch, if different character are together, we can cover them in single turn
        // so continue chunk will be in one operation
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return rec(0, n-1, s);
    }
};