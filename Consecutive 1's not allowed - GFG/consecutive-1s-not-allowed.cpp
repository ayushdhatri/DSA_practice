//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	ll countStrings(int n) {
	    // code here
	    vector<vector<long long >>dp(2, vector<long long >(n+1,0));
	    dp[0][1]=1;
	    dp[1][1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        long long  zeroth = (dp[0][i-1]+dp[1][i-1])%mod; 
	        long long  oneth=dp[0][i-1]%mod;
	        dp[0][i]=zeroth;
	        dp[1][i]=oneth;
	   }
	    return (dp[0][n]+dp[1][n])%mod;
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends