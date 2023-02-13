//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1, 0));
        for(int i=0;i<N;i++) dp[i][0]=0;
        for(int i=1;i<=W;i++)
            if(i>=wt[0]) 
                dp[0][i]=val[0]+dp[0][i-wt[0]];
        for(int i=1;i<N;i++)
        {
            for(int ksack =1;ksack<=W;ksack++)
            {
                int notinclude = 0+dp[i-1][ksack];
                int include = INT_MIN;
                if(ksack>=wt[i])
                {
                    include = val[i]+dp[i][ksack-wt[i]];
                }
                dp[i][ksack]=max(include, notinclude);
            }
        }
        return dp[N-1][W];
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends