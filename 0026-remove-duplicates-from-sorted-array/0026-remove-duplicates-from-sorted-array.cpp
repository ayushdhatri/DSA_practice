class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int k=1;
        int i=1;
        int j=1;
        while(j<nums.size())
        {
            if(nums[j]==nums[j-1])
            {
                j++;
            }
            else
            {
                nums[i]=nums[j];
                k++;
                i++;
                j++;
            }
        }
        
        
        return k;
        
    }
};