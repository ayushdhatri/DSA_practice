//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int mod = 1e9+7;
        int range = 0;
        for(int i = 0;i<n;i++){
            range+=arr[i];
        }
        int req_sum = 0;
        if((range+d)%2==0)req_sum = (range+d)/2;
        else return 0;
        vector<vector<int>>dp(n+1, vector<int>(req_sum+1,0));
        dp[0][0]=1;
        for(int index=1;index<=n;index++){
            for(int wt = 0;wt<=req_sum;wt++){
                int pick = 0;
                int notpick = 0;
                if(arr[index-1]<=wt){
                    pick = (dp[index-1][wt-arr[index-1]])%mod;
                }
                notpick = (dp[index-1][wt])%mod;
                dp[index][wt]=(pick+notpick)%mod;
            }
        }
        return dp[n][req_sum];
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends