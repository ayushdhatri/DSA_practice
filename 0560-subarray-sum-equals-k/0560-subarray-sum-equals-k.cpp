class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>freq;
        int prefixsum=0;
        int count=0;
        freq.insert({0,1});
        
        for(int i=0;i<n;i++)
        {
           prefixsum+=nums[i];
           int checksum = prefixsum-k;
           if(freq.find(checksum)!=freq.end())
                count+=freq[checksum];
            freq[prefixsum]++;
        }
        return count;
        
        
    }
};