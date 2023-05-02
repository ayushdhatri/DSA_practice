//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1, vector<int>(W+1,0));
       
       for(int row = 0;row<=n;row++) dp[row][0]=0;
       for(int col = 0;col<=W;col++)dp[0][col]=0;
       
      for(int row=1;row<=n;row++)
      {
          for(int col = 1;col<=W;col++)
          {
              int exc = dp[row-1][col];
              int inc = INT_MIN;
              if(col>=wt[row-1])
              {
                  inc = val[row-1]+dp[row-1][col-wt[row-1]];
              }
              dp[row][col]=max(exc, inc);
               
          }
      }
       return dp[n][W];
       
       
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends