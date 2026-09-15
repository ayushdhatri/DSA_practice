class Solution {
public:
long long dp[51][51];
long long rec(int l, int r, vector<int>&values){
    // pruning


    // base case
    if(r-l <2){
        // not valid
        return 0;
    }
    
    // cache
    if(dp[l][r] != -1)return dp[l][r];

    // transition
    long long minScore = 1e18;
    for(int k = l + 1;k<r;k++){
        // triangle formed is
        long long currTriArea = values[l]*values[r]*values[k] + rec(l, k, values) + rec(k,r, values);
        minScore = min(minScore, currTriArea);
    }

    // save and return
    return dp[l][r] = minScore;
}
    int minScoreTriangulation(vector<int>& values) {
        // first I saw the constraints, its very low, so I can predict that it can be solved using some dp method
        // now I have to decide the form
        // after understanding the question, I felt like we need to find all sub interval ranges, and find sub-answers,
        // for that we can use L R dp
        // now we need to decide the meaning
        // dp[l][r] =  minimum possible score that you can achieve with some triangulation of the polygon, here l and r are the indexes
        // here I am stuck at a point, thinking about the circular property of L and R, like L can start at any point between 0 to n-1, 
        // for every L and R, I know that we can cut at lots of points, and create two kinds of space, 
        // 1. we can create sub-polygoin(with smaller value of n) 
        // 2. we can create a direct triangle.
        // we can create a cut at all the index for a L to R, from L + 2, to R-2 and 
        // so this muhcn only I able to think as of now
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return (int)rec(0, n-1, values);

    }
};