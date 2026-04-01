class Solution {
public:
void merge(int low, int mid, int high, vector<int>&nums){
    // we have two sorted array and we want to merge them
    // 1 sorted array is from low to mid
    // 2nd sorted array is from mid + 1, high,
    vector<int>left(mid-low+1);
    vector<int>right(high-mid);
    int k = 0;
    for(int i = low;i<=mid;i++){
        left[k++] = nums[i];
    }
    k = 0;
    for(int i = mid+1;i<=high;i++){
        right[k++] = nums[i];
    }
    int left_ptr = 0, right_ptr = 0, curr_ptr = low;
    while(left_ptr < left.size() && right_ptr < right.size()){
        if(left[left_ptr] <= right[right_ptr]){
            nums[curr_ptr++] = left[left_ptr++];
        }
        else{
            nums[curr_ptr++] = right[right_ptr++];
        }
    }
    while(left_ptr < left.size()){
        nums[curr_ptr++] = left[left_ptr++];
    }
    while(right_ptr < right.size()){
        nums[curr_ptr++] = right[right_ptr++];
    }
}
void mergeSort(int low, int high, vector<int>&nums){
    if(low >= high)return;
    int mid = low + (high-low)/2;
    mergeSort(low, mid, nums);
    mergeSort(mid+1, high, nums);
    merge(low,mid,high, nums);
}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        return nums;
        
    }
};