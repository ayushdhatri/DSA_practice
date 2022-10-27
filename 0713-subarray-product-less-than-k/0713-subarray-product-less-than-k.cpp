class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int i=0, j=0;
        int product=1;
        int n = nums.size();
        int ans=0;
        while(j<n)
        {
            product=product*nums[j];
            if(product<k)
            {
                ans+=(j-i+1);
                j++;
            }
            else
            {
                while(i<=j&&product>=k)
                {
                    product = product/nums[i];
                    i++;
                }
                if(product<k)
                {
                    ans+=(j-i+1);
                }
                j++;
            }
            
        }
        return ans;
        
        
        
    }
};