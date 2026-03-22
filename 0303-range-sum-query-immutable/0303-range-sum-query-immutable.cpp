class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i= 1;i<nums.size();i++){
            arr[i] = arr[i-1] + arr[i];
        }
    }
    
    int sumRange(int left, int right) { 
        int sum = left == 0 ? arr[right] : arr[right] - arr[left-1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */