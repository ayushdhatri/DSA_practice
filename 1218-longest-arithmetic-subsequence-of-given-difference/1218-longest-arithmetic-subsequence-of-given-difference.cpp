class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // if I apply dp here :
        // TC : O(N^2)
        // dp ending at I; I can find the lcs with difference d
        // so I can do it in O(n^2)|
        // but arr lenght is 10^5 * 10^5 = 10^10
        // so from j =0 to j<i, then in that case we need to find which element having difference, and it is lower index, so find that 
        int n = arr.size();
        unordered_map<int, int> dp;
        int lis = 1;
        int maxLen = 1;
        for(int i = 0;i<n;i++){
            int prevDiffLen = dp.count(arr[i] - difference) ? dp[arr[i] - difference] : 0;
            lis = 1 + prevDiffLen;
            dp[arr[i]] = lis;
            maxLen= max(maxLen, lis);
        }
        return maxLen;
    }
};