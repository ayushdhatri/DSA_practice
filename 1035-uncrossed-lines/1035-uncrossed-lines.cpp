class Solution {
public:
int dp[501][501];
int rec(int level1, int level2, vector<int>&nums1, vector<int>&nums2){
    // pruning

    // base case
    if(level1 >= nums1.size() || level2 >= nums2.size())return 0;
    // cache
    if(dp[level1][level2] != -1)return dp[level1][level2];

    // transition
    int ans = 0;
    if(nums1[level1] == nums2[level2]){
        ans = max(ans, 1 + rec(level1 + 1, level2 + 1, nums1, nums2));
    }
    else{
        int way1 = rec(level1 + 1, level2, nums1, nums2);
        int way2 = rec(level1, level2 + 1, nums1, nums2);
        ans = max({ans, way1, way2});
    }

    // save and return
    return dp[level1][level2] = ans;
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // we need to find maximum number of connecting lines
        // which means we need to maximize the connecting line
        // connecting lines should not intersect
        // a number in nums1 can match with a number in nums2
        // when we can have a intersecting line?
        // 1 4 2
        // 1 2 4 2
        //  both of them should have common elements and it should be in sequence
        // we need to find the lcs of two string
        memset(dp, -1, sizeof(dp));
        return rec(0,0,nums1, nums2);
        
    }
};