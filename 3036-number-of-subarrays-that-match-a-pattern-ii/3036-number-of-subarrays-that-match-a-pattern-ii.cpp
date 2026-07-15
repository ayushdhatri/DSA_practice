class Solution {
public:
vector<int> findKMP(vector<int>&nums, vector<int>&pattern){

    int n = nums.size();
    int m = pattern.size();
    vector<int>combArr(n+m+1);
    int k = 0;
    for(int i = 0;i<m;i++){
        combArr[k++] = pattern[i];
    }
    combArr[k++] = -2;// act as seperator
    for(int i = 0;i<n;i++){
        combArr[k++] = nums[i];
    }
    // we pushed everything in one array now find longest prefix which is suffix
    vector<int>kmpArr(combArr.size()+1);
    int i = 0, j = -1;
    kmpArr[0] = -1;
    while(i<combArr.size()){
        while(j!=-1 && combArr[i] != combArr[j]){
            j = kmpArr[j];
        }
        i++;
        j++;
        kmpArr[i] = j;
    }
    return kmpArr;

}
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector<int>condArr(n-1);
        for(int i = 0;i<n-1;i++){
            int value;
            if(nums[i+1] > nums[i]){
                value = 1;
            }
            else if(nums[i+1] == nums[i]){
                value = 0;
            }
            else{
                value = -1;
            }
            condArr[i] = value;
        }
        vector<int>kmpArr = findKMP(condArr, pattern);
        int count = 0;
        // count all subarray where size is m
        // its better to skip start m array
        for(int i = pattern.size()+1;i<kmpArr.size();i++){
            if(kmpArr[i] == pattern.size()){
                count++;
            }
        }
        return count;


        
    }
};