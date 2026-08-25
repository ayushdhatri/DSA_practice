class Solution {
public:
int dp[110];
int rec(int level, vector<int>&nums){
    // pruning
    if(level >= nums.size())return 0;

    // base case


    // cache
    if(dp[level] != -1)return dp[level];
    // transition
    int take = nums[level] + rec(level + 2, nums);
    int dontTake = rec(level + 1, nums);

    // save and return
    return dp[level] = max(take, dontTake);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>arr1(n-1), arr2(n-1);
        int m = n-1;
        for(int i = 0;i<m;i++){
            arr1[i] = nums[i];
        }
        // cout<<"Size of arr2 : "<<arr2.size()<<endl;
        for(int i = 0;i<m;i++){
            arr2[i] = nums[i+1];
        }
        memset(dp, -1, sizeof(dp));
        int max1 = rec(0,arr1);
        memset(dp, -1, sizeof(dp));
        int max2 = rec(0, arr2);
        return max(max1, max2);
        
    }
};