class Solution {
public:
    static bool comp(pair<int, int>a, pair<int, int>b)
    {
        if(a.first<b.first)
            return true;
        
        if(a.first == b.first)
        {
            return a.second>b.second;
        }
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int, int>freq;
        for(int i=0;i<n;i++)
        {
                freq[nums[i]]++;
        }
        vector<pair<int, int>>ele;
        for(auto x: freq)
        {
            ele.push_back({x.second,x.first});// first element is frequency
        }
        sort(ele.begin(), ele.end(), comp);
        for(auto x: ele)
        {
            int k = x.first;
            while(k--)
                ans.push_back(x.second);
        }
        
        return ans;
        
    }
};