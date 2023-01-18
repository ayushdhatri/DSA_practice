class Solution {
public:
    void merge(int low, int mid, int high, vector<int>&nums, long long int &countinv)
    {
        int n = mid-low+1;
        int m = high-mid;
        int left[n];
        int right[m];
        for(int i=0;i<n;i++)
            left[i]=nums[i+low];
        for(int i=0;i<m;i++)
            right[i]=nums[i+mid+1];
        int i=0,j=0;
        int k = low;
        
        while(i<n&&j<m)
        {
            if(left[i]<=right[j])nums[k++]=left[i++];
            else {
                countinv+=(n-i);
                nums[k++]=right[j++];
            }
        }
        while(i<n)nums[k++]=left[i++];
        while(j<m)nums[k++]=right[j++];
        
    }
    void mergesort(int low, int high, vector<int>&nums, long long int &countinv)
    {
        if(low<high)
        {
            int mid = low + (high-low)/2;
            mergesort(low, mid,nums,countinv);
            mergesort(mid+1,high, nums, countinv);
            merge(low, mid, high, nums, countinv);
        }
        
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        long long int countinv = 0;
        long long int countloc = 0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])countloc++;
        }
        mergesort(0, n-1, nums, countinv);
        
      
        
        
        return countinv==countloc;
        
    }
};