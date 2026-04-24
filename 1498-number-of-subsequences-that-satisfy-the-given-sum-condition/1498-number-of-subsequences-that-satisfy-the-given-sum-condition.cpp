#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // Step 1: Sort the array so we can use the 2^(R-L) math and two pointers
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int mod = 1e9 + 7;
        
        // Step 2: Precompute powers of 2 modulo 1e9+7 to avoid overflow and save time
        // power[i] will store (2^i) % mod
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        
        // Step 3: Converging Two Pointers setup
        int left = 0;
        int right = n - 1;
        int count = 0;
        
        while (left <= right) {
            // If the sum of min and max is valid
            if (nums[left] + nums[right] <= target) {
                // Add all possible subsequences formed between left and right
                count = (count + power[right - left]) % mod;
                
                // Move the left pointer to increase the minimum and find new sets
                left++;
            } else {
                // The sum is too big, so we must decrease our maximum
                right--;
            }
        }
        
        return count;
    }
};