class Solution {
public:
    int dp[31][3010];
    bool rec(int level, int target, vector<int>&stones){
        // pruining

        // base case
        if(target == 0)return true;
        if(level == stones.size()){
            return target == 0;
        }

        // cache
        // cout<<"prinint level and target : "<<level<<" "<<target<<endl;
        if(dp[level][target] != -1)return dp[level][target];

        // transition


        // save and return
        return dp[level][target] = rec(level + 1, target, stones) || (target >= stones[level] ? rec(level + 1, target - stones[level], stones) : false);
    }
    int lastStoneWeightII(vector<int>& stones) {
        // sort : 
        // 2 7 4 1 8 1
        //   = 23 /2 =11 = 12
        // {7 , 4}    {1, 8, 1, 2}
        // {, } {1, 1, 2, }
        // totalSum = 151 
        // 151 / 2 = 73, 151 - 73 - 73 =  151 - 146 = 5 
        if(stones.size() == 1)return stones[0];
        int totalStoneWeight = 0;
        int n = stones.size();
        for(auto &v : stones){
            totalStoneWeight+=v;
        }
        memset(dp, -1, sizeof(dp));
        int targetSum = totalStoneWeight/2;
        int miniAns = INT_MAX;
        for(int i = targetSum;i>=1;i--){
            if(rec(0, i, stones)){
                // cout<<"fine tune targeSum and totalStoneWeight"
                miniAns = totalStoneWeight - 2*i;
                break;
            }
        }
        return miniAns;

    }
};