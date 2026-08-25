class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 0); // Stores max positive-product length ending at i
        vector<int> dp2(n, 0); // Stores max negative-product length ending at i

        // Base case for index 0
        if (nums[0] > 0) {
            dp1[0] = 1;
        } else if (nums[0] < 0) {
            dp2[0] = 1;
        }
        
        int ans = dp1[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                dp1[i] = dp1[i - 1] + 1;
                dp2[i] = (dp2[i - 1] > 0) ? dp2[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                dp1[i] = (dp2[i - 1] > 0) ? dp2[i - 1] + 1 : 0;
                dp2[i] = dp1[i - 1] + 1;
            } else { // nums[i] == 0 resets both lengths to 0
                dp1[i] = 0;
                dp2[i] = 0;
            }

            ans = max(ans, dp1[i]);
        }

        // // Optional debugging outputs matching your pattern
        // for (int i = 0; i < n; i++) {
        //     cout << dp1[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << dp2[i] << " ";
        // }
        // cout << endl;

        return ans;
    }
};