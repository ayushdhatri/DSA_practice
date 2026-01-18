class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        int n = nums1.size(), m = nums2.size();

        // base case: no valid pair possible
        if (i == n || j == m) return INT_MIN / 4;

        if (dp[i][j] != INT_MIN) return dp[i][j];

        // option1: skip nums1[i]
        int ans = solve(i + 1, j, nums1, nums2, dp);

        // option2: skip nums2[j]
        ans = max(ans, solve(i, j + 1, nums1, nums2, dp));

        // option3: take pair (i, j)
        int take = nums1[i] * nums2[j];

        // // extend only if it helps
         int next = solve(i + 1, j + 1, nums1, nums2, dp);
         take = max(take, take + max(0, next));

        ans = max(ans, take);

        return dp[i][j] = ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return solve(0, 0, nums1, nums2, dp);
    }
};
