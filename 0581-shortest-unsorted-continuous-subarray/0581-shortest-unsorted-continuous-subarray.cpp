class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans=nums;
        sort(ans.begin(), ans.end());
        if(nums== ans||ans.size()==1)
            return 0;
            
        int i=0, j=n-1;
        while(i<n)
        {
            if(ans[i]!=nums[i])
                break;
            i++;
        }
        while(j>=0)
        {
            if(ans[j]!=nums[j])
                break;
            j--;
        }
        return j-i+1;
        
    }
};