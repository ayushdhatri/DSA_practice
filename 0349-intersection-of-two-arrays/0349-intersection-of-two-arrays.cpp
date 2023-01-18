class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(auto x: nums1)
            s1.insert(x);
        for(auto x: nums2)
            s2.insert(x);
        vector<int>ans;
        for(auto x: s1)
        {
            int ele = x;
            if(s2.find(ele)!=s2.end())
                ans.push_back(ele);
        }
        
        return ans;
        
        
    }
};