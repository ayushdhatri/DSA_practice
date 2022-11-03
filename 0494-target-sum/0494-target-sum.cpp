class Solution {
public:
    int noofways(int index, vector<int>&nums, int target)
    {
        if(index==0)
        {
            if(target==0&&nums[0]==0)
                return 2;
            if(target+nums[0]==0||target-nums[0]==0)
                return 1;
            return 0;
        }
        // there are two ways either i can apply + symbol or - symbol
        int sum = noofways(index-1, nums, target+nums[index]);
        int minus = noofways(index-1, nums, target-nums[index]);
        return sum+minus;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        return noofways(n-1, nums, target);
        
    }
};