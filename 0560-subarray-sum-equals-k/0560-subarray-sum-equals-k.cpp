class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //
        int n = nums.size();
        unordered_map<int, int>freq;
        int prefix_sum = 0;
        freq[prefix_sum]=1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            prefix_sum+=nums[i];
            
            int temp = prefix_sum-k;
            if(freq.find(temp)!=freq.end()){
                ans +=freq[temp];
            }
            freq[prefix_sum]+=1;

        }
        return ans;




        
    }
};