class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        vector<int>ans(n, -1);
        if(n <= k)return ans;
        for(int i = k;i<(n-k);i++){
            int left = i -k;
            int right = i + k;
            if(left == right){
                ans[i] = nums[i];
            }
            else{
                ans[i] = (left == 0) ? (prefixSum[right])/(2*k + 1) : (prefixSum[right] - prefixSum[left-1])/(2*k + 1);
            }
        }
        return ans;
        
    }
};