class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j = 0;
        int n = nums.size();
        double sum=0;
        double ans  = INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            if((j-i+1)<k)
                j++;
            else if((j-i+1)==k)
            {
                double temp = sum/k;
                ans = max(ans, temp);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
        
        
    }
};