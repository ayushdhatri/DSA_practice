class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            freq[nums[i]]+=1;
        }
        vector<vector<int>>bucket(n+1);
        for(auto x: freq){
            bucket[x.second].push_back(x.first);
        }
        int ele_count = k;
        vector<int>ans;
        for(int i= n;i>=0;i--){
            if(ele_count == 0)break;
            if(bucket[i].size() !=0){
                for(auto x: bucket[i]){
                    ans.push_back(x);
                    ele_count--;
                }
            }
        }
        return ans;




        
    }
};