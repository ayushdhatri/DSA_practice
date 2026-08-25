class Solution {
public:
int dp[10100];
int rec(int level, int lastLevel, vector<int>&nums, unordered_map<int, int>&freq){
    // pruning
    if(level > lastLevel){
        return 0;
    }

    // base case

    // cache
    if(dp[level] != -1)return dp[level];

    // transition
    int pick = freq[level]*level + rec(level + 2, lastLevel, nums, freq);
    int notPick = rec(level + 1, lastLevel, nums, freq);
    // save and return
    return dp[level] = max(pick, notPick);
}
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(auto &x : nums){
            freq[x]+=1;
        }
        int last_val = 10000;
        memset(dp, -1, sizeof(dp));
        return rec(0, last_val, nums,freq);
        
        
    }
};