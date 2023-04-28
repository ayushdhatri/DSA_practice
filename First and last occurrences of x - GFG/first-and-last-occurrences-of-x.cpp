//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int last(int arr[] ,int n, int x)
{
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==x)
        {
            ans = mid;
           low = mid+1;
        }
        else if(arr[mid]>x)
        {
            high = mid-1;
        }
        else 
            low = mid+1;
    }
    return ans;
}
int first(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==x)
        {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid]>x)
        {
            high = mid-1;
        }
        else 
            low = mid+1;
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>ans;
    int a = first(arr, n, x);
    int b = last(arr, n, x);
    ans.push_back(a);
     ans.push_back(b);
    return ans;
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends