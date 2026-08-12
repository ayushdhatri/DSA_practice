class Solution {
public:
struct prefix_sum{
    vector<int>preSum;
    prefix_sum(){}
    void build(vector<int>&nums){
        // we will build the prefix sum 
        preSum.assign(nums.size(), 0);
        preSum[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            preSum[i] = nums[i] + preSum[i-1];
        }
    }
    int findPrefixSum(int l, int r){
        // here we are considering our l and r to be zero based
        if(l == 0){
            return preSum[r];
        }
        return preSum[r] - preSum[l-1];
    }


}m;
    int dp[20100][4];
    int N;
    int K;
    int rec(int level, int rem, vector<int>&nums){
        // pruning
        if(rem == 0){
            return 0;
        }
        if(level + rem * K > N)return -1e9;


        // cache 
        if(dp[level][rem] != -1)return dp[level][rem];

        // transition
        int dontTake = rec(level + 1, rem, nums);
        int take  = m.findPrefixSum(level, level + K -1) + rec(level + K, rem - 1, nums);

        // save and return
        return dp[level][rem] = max(dontTake, take);
    }

    void generate(int level, int rem, vector<int>&subset, vector<int>&nums){
        if(level == nums.size() || rem == 0 || (level + rem * K > N)){
            return;
        }
        int skip = rec(level + 1, rem, nums);
        int take = m.findPrefixSum(level, level + K -1) + rec(level + K, rem -1, nums);
        if(take >= skip){
            subset.push_back(level);
            generate(level + K, rem -1, subset, nums);
        }
        else{
            generate(level + 1, rem, subset, nums);
        }




    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        N = n;
        K = k;
        memset(dp, -1, sizeof(dp));
        m.build(nums);// build the prefixSum
        rec(0,3,nums);
        vector<int>subset;
        generate(0, 3, subset, nums);


        return subset;
        
    }
};