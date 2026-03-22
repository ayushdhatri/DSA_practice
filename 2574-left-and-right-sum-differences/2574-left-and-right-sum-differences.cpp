class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefixSum(n);
        vector<int>ans;
        int count = 0;
        int totalSum = 0;
        for(int i = 0;i<n;i++){
            totalSum+=nums[i];
        }
        prefixSum[0] = nums[0];
        ans.push_back(totalSum - nums[0]);
        for(int i= 1;i<n-1;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            int leftSum = prefixSum[i-1];
            int rightSum = totalSum - prefixSum[i];
            ans.push_back(abs(leftSum - rightSum));
            
        }
        if(n >=2)
        ans.push_back(prefixSum[n-2]);
        return ans;

            
    }
};