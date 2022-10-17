class Solution {
public:
  
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n, 0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int notpick = 0 + dp[i-1];
            int pick = nums[i];
            if(i-2>=0)
            {
                pick+= dp[i-2];
            }
            dp[i]=max(pick, notpick);
        }
        return dp[n-1];
    }
};