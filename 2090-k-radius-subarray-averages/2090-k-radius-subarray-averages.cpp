#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        vector<int> ans(n, -1);
        int window_len = 2*k+1;
        int tail = 0, head = 0;
        ll sum = 0;
        while(head < n){
            if(head - tail + 1 < window_len){
                sum+=nums[head];
                head+=1;
            }
            else if(head - tail + 1 == window_len){
                sum+=nums[head];
                ans[tail + k] = (sum/(1LL*window_len));
                sum-=nums[tail];
                tail+=1;
                head+=1;
            }
        }
        


        return ans;
    }
};