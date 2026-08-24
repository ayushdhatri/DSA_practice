class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // we can have dp[i] = maximum subarray ending at i
        int n = nums.size();
        vector<int>dp1(n, 1);
        vector<int>dp2(n, 1);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            dp1[i] = max({nums[i], nums[i] * dp1[i-1], nums[i] * dp2[i-1]});
            dp2[i] = min({nums[i], nums[i] * dp1[i-1], nums[i] * dp2[i-1]});
            ans = max(ans, dp1[i]);
         
        }
        return ans;
    }
};