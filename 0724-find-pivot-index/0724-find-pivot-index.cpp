class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int totalSum = 0;
        for(int i = 0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(prev == (totalSum-prev-nums[i])){
                ans  = i;
                break;
            }
            prev+=nums[i];
        }
        return ans;
        
    }
};