class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int n = nums.size();
        unordered_map<int, bool>freq;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]=true;
        }
        for(auto x: freq)
        {
            int prev = x.first-1;
            if(freq.find(prev)!=freq.end())
            {
                freq[x.first]=false;
            }
        }
       
        int ans = 0;
        for(auto x: freq)
        {
            
            if(x.second==true)
            {
                int count=1;
                int element = x.first;
                while(freq.find(element+1)!=freq.end())
                {
                    element++;
                    count++;
                }
                ans= max(ans, count);
                
            }
        }
        
        
        return ans;
       
    }
};