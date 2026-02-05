const int INF = 1e9;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // I will define the maeaning  : dp[i] maxium product of subarray ending at i
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2, -INF));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];

        for(int i = 1;i<n;i++){
           int curr = nums[i];
           int currMax = nums[i] * dp[i-1][0];
           int currMin = nums[i] * dp[i-1][1];
           dp[i][0] = max({curr, currMax, currMin});
           dp[i][1] = min({curr, currMax, currMin});
        }
        int ans = -INF;
        for(int i = 0;i<n;i++){
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            ans = max({ans,dp[i][0],dp[i][1]});
        }
        return ans;

        
    }
};