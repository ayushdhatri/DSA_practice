class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1)
            return nums;
        deque<int>maxq;
        int i=0;
        int j=0;
        int n = nums.size();
        vector<int>ans;
        while(j<n)
        {
            if(maxq.size()==0)
                maxq.push_back(nums[j]);
            else
            {
                while(maxq.size()!=0&&nums[j]>maxq.back())
                    maxq.pop_back();
                maxq.push_back(nums[j]);
            }
            if((j-i+1)<k)
                j++;
            else if((j-i+1)==k)
            {
                ans.push_back(maxq.front());
                if(maxq.front()==nums[i])
                    maxq.pop_front();
                i++;
                j++;
                
            }
        }
        return ans;
        
        
    }
};