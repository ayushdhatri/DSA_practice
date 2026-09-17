class Solution {
public:
int dp[310][310];
int rec(int start, int end, vector<int>&arr){
    // pruning


    // base case
    if(start+1 == end){
        // mean no more ballons to burst
        return 0;
    }

    // cache
    if(dp[start][end] != -1 )return dp[start][end];

    // tarnsition
    int maxScore = INT_MIN;
    for(int lastBallonBurst = start+1;lastBallonBurst<end;lastBallonBurst++){
        maxScore = max(maxScore, (arr[start] * arr[lastBallonBurst] * arr[end]) + rec(start, lastBallonBurst, arr)+
        rec(lastBallonBurst, end,arr));
    }


    // save and return
    return dp[start][end] = maxScore;
}
    int maxCoins(vector<int>& nums) {
        // here cleverly I was able to think with help of test case that greedy will not work
        // to handle 0 and n-1 ballon I will add a boundry 
        // 1 at start and 1 at end so that it becomes safe and to prevent out of bound
        // here what I am thinking and where I am stuck is
        // here I identified that something is getting burst and at end we are not having any values
        // so kind of similarity with L R dp type
        // now from onwards, I am not able to think what to do
        // I draw the diagram as well
        // like how at last only 1 element is left so how to derive the previous state, but did not 
        // got any idea or hint
        int n = nums.size();
        vector<int>arr(n+2);
        arr[0] = 1;arr[n+1] = 1;
        for(int i = 1;i<=n;i++){
            arr[i] = nums[i-1];
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, n+1, arr);

    }
};