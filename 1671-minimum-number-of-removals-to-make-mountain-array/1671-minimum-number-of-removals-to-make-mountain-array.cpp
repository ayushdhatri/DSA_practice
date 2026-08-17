class Solution {
public:

int lis[1010];
int rec(int level, vector<int>&arr){
    if(lis[level] != -1)return lis[level];
    // transitino
    int maxLen = 1;
    for(int prevIndex = level-1;prevIndex>=0;prevIndex--){
        if(arr[prevIndex] < arr[level]){
            maxLen = max(maxLen, 1 + rec(prevIndex, arr));
        }
    }
    // save and return
    return lis[level] = maxLen;
}
vector<int> findLis(vector<int>&arr){
    int n = arr.size();
    vector<int>lisArr(n);
    memset(lis, -1, sizeof(lis));
    for(int i = n-1;i>=0;i--){
        rec(i, arr);
    }
    for(int i = 0;i<n;i++){
        lisArr[i] = lis[i];
    }
    return lisArr;

}
    int minimumMountainRemovals(vector<int>& nums) {
        // here we need to lis array 
        // one lis array indicating lis1[i] = lis ending at i from o to i
        // one lis array indicating lis2[i] = lis end at i starting from n-1
        int n = nums.size();
        vector<int>lis1 = findLis(nums);
        reverse(nums.begin(), nums.end());
        vector<int>lis2 = findLis(nums);
        reverse(nums.begin(), nums.end());
        reverse(lis2.begin(), lis2.end());

        for(int i = 0;i<n;i++){
            cout<<lis1[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i<n;i++){
            cout<<lis2[i]<<" ";
        }

        int minimumElementToRemove = n;
        for(int i = 0;i<n;i++){
            if(lis1[i] > 1 && lis2[i] > 1){
                int leftMountainAtI = lis1[i];
                int rightMountainAtI = lis2[i];
                cout<<"At index i :"<<leftMountainAtI<<" "<<rightMountainAtI<<endl;
                minimumElementToRemove = min(minimumElementToRemove, (n - (leftMountainAtI+rightMountainAtI-1)));
            }
        }
        return minimumElementToRemove;


    }
};