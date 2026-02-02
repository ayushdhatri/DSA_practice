class Solution {
public:
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if we can split array into k or fewer subarrays
        // with each subarray sum <= mid
        if (canSplit(nums, k, mid)) {
            ans = mid;
            high = mid - 1;  // Try for smaller max sum
        } else {
            low = mid + 1;   // Need larger max sum
        }
    }
    return ans;
}

bool canSplit(vector<int>& nums, int k, int maxSum) {
    int subarrays = 1;
    int currentSum = 0;
    
    for (int num : nums) {
        if (currentSum + num > maxSum) {
            subarrays++;
            currentSum = num;
            if (subarrays > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}
};