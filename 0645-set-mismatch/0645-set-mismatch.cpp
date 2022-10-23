class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n+1, 0);
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]]++;
        }
        vector<int>ans;
        int missing=-1, repeat=-1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==0)missing = i;
            if(arr[i]==2)repeat= i;
        }
        ans.push_back(repeat);
        ans.push_back(missing);
        return ans;
        
        
    }
};