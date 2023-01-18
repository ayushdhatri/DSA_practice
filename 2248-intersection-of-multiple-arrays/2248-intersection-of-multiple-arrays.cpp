class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int>freq;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(auto x: nums[i])
                freq[x]++;
        }
        vector<int>ans;
        for(auto x: freq)
        {
            int count = x.second;
            if(count==n)ans.push_back(x.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};