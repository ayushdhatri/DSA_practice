//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxpossible(int index, int wt[], int val[], int total, vector<vector<int>>&dp)
        {
            if(total==0)
            {
                return 0;
            }
            if(index==0)
            {
              if(total>=wt[index])
               return val[index];
               return 0;
            }
            if(dp[index][total]!=-1)
                return dp[index][total];
            
            int pick = 0;
            if(total>=wt[index])
                pick = val[index] + maxpossible(index-1, wt, val, total-wt[index], dp);
            int notpick = maxpossible(index-1, wt, val, total,dp);
            return dp[index][total]=max(pick, notpick);
        }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n, vector<int>(W+1, -1));
       return maxpossible(n-1, wt, val, W,dp);
       
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