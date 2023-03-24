//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool twopointer(int arr[], int block, int target, int n )
    {
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if(i==block)
            {
                i++;
                continue;
            }
            else if(j==block)
            {
                j--;
                continue;
            }
            else{
                int currsum = arr[i]+arr[j];
                if(currsum<target)
                i++;
                else if(currsum == target)
                {
                    return true;
                }
                else
                j--;
            }
        }
        return false;
        
    }
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i = 0;i<n;i++)
        {
            int targetsum = X-A[i];
            if(targetsum<0)continue;
            bool temp = twopointer(A, i, targetsum, n);
            if(temp==true)return true;
        }
        return false;
        
        
        
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends