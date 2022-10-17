class Solution {
public:
    int houserob(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int notpick = 0 + dp[i-1];
            int pick  = nums[i];
            if(i-2>=0)
            {
                pick+=dp[i-2];
            }
            dp[i]=max(pick, notpick);
        }
        return dp[n-1];
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n = nums.size();
        vector<int>nums1(n-1);
        for(int i=0;i<n-1;i++)nums1[i]=nums[i];
        vector<int>nums2(n-1);
        for(int i=1;i<n;i++)nums2[i-1]=nums[i];
        int ans1 = houserob(nums1);
        int ans2 = houserob(nums2);
        return max(ans1, ans2);
        
        
        
    }
};