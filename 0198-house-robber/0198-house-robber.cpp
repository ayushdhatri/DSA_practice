class Solution {
public:
    int houserob(int index, vector<int>&nums, vector<int>&dp)
    {
        if(index<0)
            return 0;
        if(index==0)
            return nums[0];
        if(dp[index]!=-1)
            return dp[index];
        int pick = nums[index]+houserob(index-2, nums, dp);
        int notpick = 0 + houserob(index-1, nums, dp);
        return dp[index]=max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n = nums.size();
        vector<int>dp(n, -1);
        return houserob(n-1, nums, dp);
        
    }
};