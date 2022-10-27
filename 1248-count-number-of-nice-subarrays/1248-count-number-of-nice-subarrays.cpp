class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1)
               nums[i]=1;  
            else
                nums[i]=0;
        }
        unordered_map<int, int>freq;
        int prefixsum=0;
        freq.insert({0,1});
        int ans=0;
        for(int i=0;i<n;i++)
        {
            prefixsum+=nums[i];
            int checksum = prefixsum-k;
            if(freq.find(checksum)!=freq.end())
                ans+=freq[checksum];
            freq[prefixsum]++;
        }
        return ans;
    }
};