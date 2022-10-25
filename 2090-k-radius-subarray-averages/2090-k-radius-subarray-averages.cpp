class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)
            return nums;
        int n = nums.size();
        vector<int>ans(n,-1);
        if(n<(2*k+1))
            return ans;
        long long int sum=0;
        for(int i=0;i<(2*k+1);i++)
            sum+=nums[i];
        ans[k]=sum/(2*k+1);
        for(int j=2*k+1, cp=k+1, i=0;j<n;j++,cp++,i++)
        {
            sum-=nums[i];
            sum+=nums[j];
            ans[cp]=sum/(2*k+1);
        }
        return ans;
    }
};