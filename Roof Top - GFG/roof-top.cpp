//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int arr[], int N)
    {
       //Your code here
     int last = arr[0];
     int i = 1;
     int ans = 0;
     int temp = 0;
     while(i<N)
     {
         
         if(arr[i]>last)
         {
             temp++;
             ans = max(ans, temp);
             last = arr[i];
         }
         else{
             temp = 0;
             last = arr[i];
             
         }
         i++;
     }
     return ans;
     
       
    }
};

//{ Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends