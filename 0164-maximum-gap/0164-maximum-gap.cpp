class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)return 0;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int range = high - low;
        if(range == 0)return 0;
        
        vector<int>minBucket(n, INT_MAX);
        vector<int>maxBucket(n, INT_MIN);

        for(int i = 0;i<n;i++){
            int bi = (int)((double)(nums[i] - low)/range * (n-1));
            minBucket[bi] = min(minBucket[bi], nums[i]);
            maxBucket[bi] = max(maxBucket[bi], nums[i]);
        }

        // we will start traversing and find the differenc
        int ans = INT_MIN;
        int prev = 0;
        for(int i = 1;i<n;i++){
            if(minBucket[i] == INT_MAX)continue;
            ans = max(ans, minBucket[i]- maxBucket[prev]);
            prev = i;
        }
        return ans;
    }
};