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
              if(total>=wt[0])
               return val[0];
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
       vector<vector<int>>dp(n, vector<int>(W+1, 0));
       for(int i=0;i<n;i++)
       {
           dp[i][0]=0;
       }
       for(int index=wt[0];index<=W;index++)
        dp[0][index]=val[0];
       if(wt[0]<=W)
            dp[0][wt[0]]=val[0];
        for(int i=1;i<n;i++)
        {
            for(int j =1;j<W+1;j++)
            {
                int pick = 0;
                if(j>=wt[i])
                    pick = val[i]+dp[i-1][j-wt[i]];
                int notpick = dp[i-1][j];
                dp[i][j]=max(pick, notpick);
            }
        }
        return dp[n-1][W];
       
       //return maxpossible(n-1, wt, val, W,dp);
       
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