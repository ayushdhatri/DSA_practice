//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>>dp(n, vector<int>(m, 0));
        // n is row and m is column
        for(int col = m-1;col>=0;col--)
        {
            for(int row = 0;row<n;row++)
            {
                if(col==m-1)
                {
                    dp[row][col]=M[row][col];
                }
                else
                {
                    if(row==0&&row==n-1)
                    {
                        dp[row][col]=M[row][col]+dp[row][col+1];
                    }
                    else{
                        if(row==0)
                        {
                            dp[row][col]=M[row][col]+max(dp[row+1][col+1],dp[row][col+1]);
                        }
                        else if(row==n-1){
                            dp[row][col]=M[row][col]+max(dp[row-1][col+1],dp[row][col+1]);
                        }else
                        {
                            dp[row][col]= M[row][col]+max({dp[row][col+1],dp[row-1][col+1],dp[row+1][col+1]});
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends