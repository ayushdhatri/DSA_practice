//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int K) {
    //code here
    // 5 6 7 8 9 10 1 2 3
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        // we have to decide either left or right
        if(arr[mid]==K)
        {
            return mid;
        }
        else if(arr[low]<=arr[mid])
        {
            if(K>=arr[low]&&K<arr[mid])
            high = mid-1;
            else 
            low = mid+1;
        }
        else
        {
            if(K>=arr[mid]&&K<=arr[high])
            low = mid+1;
            else high = mid-1;
        }
    }
    return -1;
}