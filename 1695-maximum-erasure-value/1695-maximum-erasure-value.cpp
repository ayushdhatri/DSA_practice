class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_set<int>freq;
        int sum=0;
        int i=0;
        int j = 0;
        int n  = nums.size();
        int maxans = INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            if(freq.find(nums[j])==freq.end()) {
                freq.insert(nums[j]);
                maxans=max(maxans, sum);
                j++;
                
                
            }
            else
            {
                while(freq.find(nums[j])!=freq.end())
                {
                    freq.erase(nums[i]);
                    sum-=nums[i];
                    i++;
                }
                freq.insert(nums[j]);
                maxans = max(maxans, sum);
                j++;
                
            }
        }
        return maxans;
        
        
    }
};