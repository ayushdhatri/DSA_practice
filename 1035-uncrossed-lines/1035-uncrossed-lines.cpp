class Solution {
public:
int maxConnectLine(int index1, int index2, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp){
    // pruning
    
    // base case
    if(index1 >= nums1.size() || index2 >= nums2.size())return 0;

    // cache
    if(dp[index1][index2] != -1)return dp[index1][index2];
    // transition
    int ans = 0;
    if(nums1[index1] == nums2[index2]){
        ans = 1 + maxConnectLine(index1 + 1, index2 + 1, nums1, nums2, dp);
    }
    else{
        ans = max(maxConnectLine(index1 + 1, index2, nums1, nums2, dp),
        maxConnectLine(index1, index2 + 1, nums1, nums2, dp));
    }


    // save and return
    return dp[index1][index2] = ans;



}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return maxConnectLine(0,0,nums1,nums2,dp);
        
    }
};