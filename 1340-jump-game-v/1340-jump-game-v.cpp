class Solution {
public:
int dp[1010];
int rec(int level, int d, vector<int>&arr){
    // cache
    if(dp[level] != -1)return dp[level];

    // transition
    int n = arr.size();
    int maxAtI = 1;
    for(int i = level-1;i>=0 ;i--){
        int prevIndex = i;
        if(prevIndex<0 || prevIndex < (level -d))break;
        // no after this we are in the right position
        if(arr[prevIndex] < arr[level]){
            // we can jump to prevIndex;
            maxAtI = max(maxAtI, 1 + rec(prevIndex, d, arr));
        }
        else break;
    }

    for(int i = level + 1;i<n;i++){
        int nextIndex = i;
        if(nextIndex >=n || nextIndex > (level + d))break;
        if(arr[level] > arr[nextIndex]){
            maxAtI = max(maxAtI, 1 + rec(nextIndex, d, arr));
        }
        else
            break;
    }

    // save and return
    return dp[level] = maxAtI;
}
    int maxJumps(vector<int>& arr, int d) {
        // My understanding:
        // -> from a particular place we can jump either i +d max to right and i -d max to the left provided their in defined boundry.
        //
        // we will have two array 
        // first array will store how much we can go to right within boundry of d
        // second array will store how much we can go to left within boundry of d
        // fA = [1,0,8,0,0,5,1,0,1,0,0];
        // sA = [0,0,2,0,1,2,0,0,2,0,4];
        // idx= [0,1,2,3,4,5,6,7,8,9,10]
        // what we can do can take a dp[i] storing maximum count of index we can visit if we start from that index
        //int maxIndex = 0;
        // for(int i = 0;i<n;i++){
           // maxIndex = max(maxIndex, rec(i, fA,sA, arr));
        //}
        // inside every recursion try to jump right using fa and try to jump to left using sA and store maximum you can get
        // let say sA[i] = 4, try to take 4 jump and take the maximum out of them 
        // maximum I can jump is d for sure, so time complexity is N * d + precomputation of N^2 for fA and sA
        int n = arr.size();
        int maxAns = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<n;i++){
            maxAns = max(maxAns, rec(i, d, arr));
        }
        return maxAns;
    }
};