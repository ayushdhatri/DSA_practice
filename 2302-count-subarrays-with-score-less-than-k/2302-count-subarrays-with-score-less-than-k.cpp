class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // there can be two condition
        // 1. if product is less than k then simply add more elements
        // 2. if product is greater then equal to k then remove elements
        int n = nums.size();
        long long int product = 1;
        int i=0, j=0;
        long long int  sum=0;
        long long count=0;
        while(j<n)
        {
            sum+=nums[j];
            product = sum*(j-i+1);
            if(product<k)
            {
                count+=(j-i+1);
                j++;
            }
            else
            {
                while(i<=j&&product>=k)
                {
                    sum-=nums[i];
                    i++;
                    product = sum*(j-i+1);
                }
                if(product<k)
                    count+=(j-i+1);
                j++;
                
            }
        }
        return count;
    }
};