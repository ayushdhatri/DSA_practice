class Solution {
public:
int dp[210][210];
int solve(int l, int r){
    // pruning 
    
    // base case
    if(l  >= r)return 0;

    // cache
    if(dp[l][r] != -1)return dp[l][r];

    // transition
    int amountCal = INT_MAX;
    for(int pos = l;pos<=r;pos++){
        int worstAmount = pos + max(solve(l,pos-1), solve(pos+1, r));
        amountCal = min(amountCal, worstAmount);
    }

    // save and return
    return dp[l][r] = amountCal;
}
    int getMoneyAmount(int n) {
        // I can guess any number between 1 to N range
        // any time my range lenght become 1 I got the number and I dont need to pay any cost so 0 
        // but between 1 to N can pick any number including 1 and N
        // you can fall under either of the case, guess can be higher or guess can be lower, or guess is the exact then no need to pay any cost
        // so as of now lets forget that we are guess the right number, because question asked us to find minimum amount need to win If I pick any number
        // we will only consider zero case when L == R, then its no choice
        memset(dp, -1, sizeof(dp));
        return solve(1, n);

        
    }
};