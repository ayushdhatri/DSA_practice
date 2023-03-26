//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            int element = arr[i];
            freq[element]--;
            int diff = k -element;
            if(diff<0)continue;
            if(freq.find(diff)!=freq.end())
            {
                int times = freq[diff];
                count+=times;
            }
            
        }
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends